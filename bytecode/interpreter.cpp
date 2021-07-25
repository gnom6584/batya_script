//
// Created by Name on 20.07.2021.
//

#include <stack>
#include <cstring>
#include <cmath>
#include "interpreter.hpp"
#include "codes.hpp"

using namespace std;
using namespace batya_script::bytecode;

Interpreter::Interpreter(size_t stack_size_bytes) noexcept(true) : _stack(Stack(stack_size_bytes)) {

}


template <typename T>
inline T extract(const unsigned char** ptr) {
	T value = *(T*)(*ptr);
	*ptr += sizeof(T);
	return value;
}

#define SET(type1, type2) \
case codes::set_ ## type2: { \
auto address = stack_ptr + extract<size_t>(&ptr); \
auto value = extract<type1>(&ptr); \
memcpy((void*)address, &value, sizeof(type1)); \
break; \
} \

#define LESS(type1, type2) \
case codes::less_ ## type2: { \
auto dst = stack_ptr + extract<size_t>(&ptr); \
auto src = stack_ptr + extract<size_t>(&ptr); \
auto out = stack_ptr + extract<size_t>(&ptr); \
*(bool*)out = *(type1*)(dst) < *(type1*)(src); \
break; \
}\

#define ARITHMETIC(type1, type2) \
case codes::add_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = *(type1*)dst + *(type1*)src;\
break;\
}\
case codes::subtract_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = *(type1*)dst - *(type1*)src;\
break;\
}\
case codes::multiply_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = *(type1*)dst * *(type1*)src;\
break;\
}\
case codes::divide_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = *(type1*)dst / *(type1*)src;\
break;\
}\

#define MODULUS(type1, type2) \
case codes::modulus_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = *(type1*)dst % *(type1*)src;\
break;\
}\

#define FLOAT_MODULUS(type1, type2) \
case codes::modulus_ ## type2: {\
auto dst = stack_ptr + extract<size_t>(&ptr);\
auto src = stack_ptr + extract<size_t>(&ptr);\
*(type1*)dst = std::fmod(*(type1*)dst, *(type1*)src);\
break;\
}\

#define WITH_U(x, type1, type2)\
x(type1, type2)\
x(unsigned type1, unsigned_ ## type2)\

#define COPY(n, b) \
case codes::copy_ ## n: { \
auto dst = stack_ptr + extract<size_t>(&ptr); \
auto src = stack_ptr + extract<size_t>(&ptr); \
memcpy((void*)dst, (void*)src, b); \
break; \
} \

#define EQUAL(n, b) \
case codes::equal_ ## n: { \
auto dst = stack_ptr + extract<size_t>(&ptr); \
auto src = stack_ptr + extract<size_t>(&ptr); \
auto out = stack_ptr + extract<size_t>(&ptr); \
*(bool*)out = memcmp((void*)dst, (void*) src, b) == 0; \
break; \
} \

void Interpreter::run(const vector<unsigned char>& bytecode, Stack& stack) noexcept(false) {
	auto* start_ptr = bytecode.data();
	auto* end_ptr = bytecode.data() + std::size(bytecode);
	std::stack<size_t> headers;

	auto* ptr = start_ptr;

	while(ptr != end_ptr) {
		auto code = *ptr;
		++ptr;
		auto stack_ptr = (!headers.empty() ? headers.top() : 0) + stack.bytes();
	//	printf("%s\n", codes::to_c_string[code]);
		switch (code) {
			case codes::stack_allocate: {
				stack.allocate(extract<size_t>(&ptr));
				break;
			}
			case codes::stack_free: {
				stack.free(extract<size_t>(&ptr));
				break;
			};
			case codes::heap_allocate: {
				auto bytes = extract<size_t>(&ptr);
				auto allocated_ptr = (size_t)malloc(bytes);
				auto out_ptr = extract<size_t>(&ptr);
				*(size_t*)out_ptr = allocated_ptr;
				break;
			}
			case codes::heap_free: {
				auto address = *(size_t*)extract<size_t>(&ptr);
				free((void*)address);
				break;
			}
			case codes::stack_push: {
				headers.push(stack.header());
				break;
			}
			case codes::stack_pop: {
				stack.free(stack.header() - headers.top());
				headers.pop();
				break;
			}
			case codes::go_to: {
				auto position = extract<size_t>(&ptr);
				ptr = start_ptr + position;
				break;
			}
			case codes::go_to_if: {
				auto flag = stack_ptr + extract<size_t>(&ptr);
				auto position = extract<size_t>(&ptr);
				if(*(bool*)flag)
					ptr = start_ptr + position;
				break;
			}
			case codes::copy: {
				auto dst = stack_ptr + extract<size_t>(&ptr);
				auto src = stack_ptr + extract<size_t>(&ptr);
				auto n = extract<size_t>(&ptr);
				memcpy((void*)dst, (void*)src, n);
				break;
			}
			case codes::equal: {
				auto dst = stack_ptr + extract<size_t>(&ptr);
				auto src = stack_ptr + extract<size_t>(&ptr);
				auto out = stack_ptr + extract<size_t>(&ptr);
				auto bytes = extract<size_t>(&ptr);
				*(bool*)out = memcmp((void*)dst, (void*) src, bytes) == 0;
				break;
			}

			case codes::and_boolean: {
				auto dst = stack_ptr + extract<size_t>(&ptr);
				auto src = stack_ptr + extract<size_t>(&ptr);
				*(bool*)dst = *(bool*)dst & *(bool*)src;
				break;
			}

			case codes::or_boolean: {
				auto dst = extract<size_t>(&ptr);
				auto src = extract<size_t>(&ptr);
				*(bool*)dst = *(bool*)dst | *(bool*)src;
				break;
			}

			case codes::signal: {
				auto str = extract<const char*>(&ptr);
				printf("%s", str);
				break;
			}

			COPY(8, 1)
			COPY(16, 2)
			COPY(32, 4)
			COPY(64, 8)
			EQUAL(8, 1)
			EQUAL(16, 2)
			EQUAL(32, 4)
			EQUAL(64, 8)

			SET(bool, boolean)
			WITH_U(SET, char, integer_8)
			WITH_U(SET, short, integer_16)
			WITH_U(SET, int, integer_32)
			WITH_U(SET, long long int, integer_64)
			SET(float, float_32)
			SET(double, float_64)

			WITH_U(LESS, char, integer_8)
			WITH_U(LESS, short, integer_16)
			WITH_U(LESS, int, integer_32)
			WITH_U(LESS, long long int, integer_64)
			LESS(float, float_32)
			LESS(double, float_64)

			WITH_U(ARITHMETIC, char, integer_8)
			WITH_U(ARITHMETIC, short, integer_16)
			WITH_U(ARITHMETIC, int, integer_32)
			WITH_U(ARITHMETIC, long long int, integer_64)
			ARITHMETIC(float, float_32)
			ARITHMETIC(double, float_64)

			WITH_U(MODULUS, char, integer_8)
			WITH_U(MODULUS, short, integer_16)
			WITH_U(MODULUS, int, integer_32)
			WITH_U(MODULUS, long long int, integer_64)

			FLOAT_MODULUS(float, float_32)
			FLOAT_MODULUS(double, float_64)

			default:
			{
				ptr += codes::size_of[code];
			}
		}
	}
}
