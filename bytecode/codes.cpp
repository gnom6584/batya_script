#include "codes.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <utility>

using namespace batya_script::bytecode;

std::string codes::dump_command(const unsigned char* ptr)  noexcept(false) {
switch(*ptr) {
    case codes::stack_allocate: {
        std::stringstream ss;
        ss << "stack_allocate: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::stack_free: {
        std::stringstream ss;
        ss << "stack_free: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::heap_allocate: {
        std::stringstream ss;
        ss << "heap_allocate: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::heap_free: {
        std::stringstream ss;
        ss << "heap_free: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::memset: {
        std::stringstream ss;
        ss << "memset: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::address_from_stack: {
        std::stringstream ss;
        ss << "address_from_stack: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::stack_push: {
        std::stringstream ss;
        ss << "stack_push: ";
        size_t offset = 1;
        return std::move(ss.str());
    }
    case codes::stack_pop: {
        std::stringstream ss;
        ss << "stack_pop: ";
        size_t offset = 1;
        return std::move(ss.str());
    }
    case codes::go_to: {
        std::stringstream ss;
        ss << "go_to: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::go_to_if: {
        std::stringstream ss;
        ss << "go_to_if: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::execute_byte_code: {
        std::stringstream ss;
        ss << "execute_byte_code: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::copy: {
        std::stringstream ss;
        ss << "copy: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::equal: {
        std::stringstream ss;
        ss << "equal: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::copy_8: {
        std::stringstream ss;
        ss << "copy_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::equal_8: {
        std::stringstream ss;
        ss << "equal_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::copy_16: {
        std::stringstream ss;
        ss << "copy_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::equal_16: {
        std::stringstream ss;
        ss << "equal_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::copy_32: {
        std::stringstream ss;
        ss << "copy_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::equal_32: {
        std::stringstream ss;
        ss << "equal_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::copy_64: {
        std::stringstream ss;
        ss << "copy_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::equal_64: {
        std::stringstream ss;
        ss << "equal_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::inverse_boolean: {
        std::stringstream ss;
        ss << "inverse_boolean: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::and_boolean: {
        std::stringstream ss;
        ss << "and_boolean: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::or_boolean: {
        std::stringstream ss;
        ss << "or_boolean: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::set_boolean: {
        std::stringstream ss;
        ss << "set_boolean: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(bool*)(ptr + offset);
        offset += sizeof(bool);
        return std::move(ss.str());
    }
    case codes::set_integer_8: {
        std::stringstream ss;
        ss << "set_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(char*)(ptr + offset);
        offset += sizeof(char);
        return std::move(ss.str());
    }
    case codes::set_unsigned_integer_8: {
        std::stringstream ss;
        ss << "set_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(unsigned char*)(ptr + offset);
        offset += sizeof(unsigned char);
        return std::move(ss.str());
    }
    case codes::set_integer_16: {
        std::stringstream ss;
        ss << "set_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(short*)(ptr + offset);
        offset += sizeof(short);
        return std::move(ss.str());
    }
    case codes::set_unsigned_integer_16: {
        std::stringstream ss;
        ss << "set_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(unsigned short*)(ptr + offset);
        offset += sizeof(unsigned short);
        return std::move(ss.str());
    }
    case codes::set_integer_32: {
        std::stringstream ss;
        ss << "set_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(int*)(ptr + offset);
        offset += sizeof(int);
        return std::move(ss.str());
    }
    case codes::set_unsigned_integer_32: {
        std::stringstream ss;
        ss << "set_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(unsigned int*)(ptr + offset);
        offset += sizeof(unsigned int);
        return std::move(ss.str());
    }
    case codes::set_integer_64: {
        std::stringstream ss;
        ss << "set_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(long long int*)(ptr + offset);
        offset += sizeof(long long int);
        return std::move(ss.str());
    }
    case codes::set_unsigned_integer_64: {
        std::stringstream ss;
        ss << "set_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(unsigned long long int*)(ptr + offset);
        offset += sizeof(unsigned long long int);
        return std::move(ss.str());
    }
    case codes::set_float_32: {
        std::stringstream ss;
        ss << "set_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(float*)(ptr + offset);
        offset += sizeof(float);
        return std::move(ss.str());
    }
    case codes::set_float_64: {
        std::stringstream ss;
        ss << "set_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(double*)(ptr + offset);
        offset += sizeof(double);
        return std::move(ss.str());
    }
    case codes::less_integer_8: {
        std::stringstream ss;
        ss << "less_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_unsigned_integer_8: {
        std::stringstream ss;
        ss << "less_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_integer_16: {
        std::stringstream ss;
        ss << "less_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_unsigned_integer_16: {
        std::stringstream ss;
        ss << "less_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_integer_32: {
        std::stringstream ss;
        ss << "less_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_unsigned_integer_32: {
        std::stringstream ss;
        ss << "less_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_integer_64: {
        std::stringstream ss;
        ss << "less_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_unsigned_integer_64: {
        std::stringstream ss;
        ss << "less_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_float_32: {
        std::stringstream ss;
        ss << "less_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::less_float_64: {
        std::stringstream ss;
        ss << "less_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_integer_8: {
        std::stringstream ss;
        ss << "add_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_unsigned_integer_8: {
        std::stringstream ss;
        ss << "add_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_integer_16: {
        std::stringstream ss;
        ss << "add_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_unsigned_integer_16: {
        std::stringstream ss;
        ss << "add_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_integer_32: {
        std::stringstream ss;
        ss << "add_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_unsigned_integer_32: {
        std::stringstream ss;
        ss << "add_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_integer_64: {
        std::stringstream ss;
        ss << "add_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_unsigned_integer_64: {
        std::stringstream ss;
        ss << "add_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_float_32: {
        std::stringstream ss;
        ss << "add_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::add_float_64: {
        std::stringstream ss;
        ss << "add_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_integer_8: {
        std::stringstream ss;
        ss << "subtract_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_unsigned_integer_8: {
        std::stringstream ss;
        ss << "subtract_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_integer_16: {
        std::stringstream ss;
        ss << "subtract_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_unsigned_integer_16: {
        std::stringstream ss;
        ss << "subtract_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_integer_32: {
        std::stringstream ss;
        ss << "subtract_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_unsigned_integer_32: {
        std::stringstream ss;
        ss << "subtract_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_integer_64: {
        std::stringstream ss;
        ss << "subtract_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_unsigned_integer_64: {
        std::stringstream ss;
        ss << "subtract_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_float_32: {
        std::stringstream ss;
        ss << "subtract_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::subtract_float_64: {
        std::stringstream ss;
        ss << "subtract_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_integer_8: {
        std::stringstream ss;
        ss << "multiply_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_unsigned_integer_8: {
        std::stringstream ss;
        ss << "multiply_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_integer_16: {
        std::stringstream ss;
        ss << "multiply_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_unsigned_integer_16: {
        std::stringstream ss;
        ss << "multiply_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_integer_32: {
        std::stringstream ss;
        ss << "multiply_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_unsigned_integer_32: {
        std::stringstream ss;
        ss << "multiply_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_integer_64: {
        std::stringstream ss;
        ss << "multiply_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_unsigned_integer_64: {
        std::stringstream ss;
        ss << "multiply_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_float_32: {
        std::stringstream ss;
        ss << "multiply_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::multiply_float_64: {
        std::stringstream ss;
        ss << "multiply_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_integer_8: {
        std::stringstream ss;
        ss << "divide_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_unsigned_integer_8: {
        std::stringstream ss;
        ss << "divide_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_integer_16: {
        std::stringstream ss;
        ss << "divide_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_unsigned_integer_16: {
        std::stringstream ss;
        ss << "divide_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_integer_32: {
        std::stringstream ss;
        ss << "divide_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_unsigned_integer_32: {
        std::stringstream ss;
        ss << "divide_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_integer_64: {
        std::stringstream ss;
        ss << "divide_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_unsigned_integer_64: {
        std::stringstream ss;
        ss << "divide_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_float_32: {
        std::stringstream ss;
        ss << "divide_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::divide_float_64: {
        std::stringstream ss;
        ss << "divide_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_integer_8: {
        std::stringstream ss;
        ss << "modulus_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_unsigned_integer_8: {
        std::stringstream ss;
        ss << "modulus_unsigned_integer_8: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_integer_16: {
        std::stringstream ss;
        ss << "modulus_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_unsigned_integer_16: {
        std::stringstream ss;
        ss << "modulus_unsigned_integer_16: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_integer_32: {
        std::stringstream ss;
        ss << "modulus_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_unsigned_integer_32: {
        std::stringstream ss;
        ss << "modulus_unsigned_integer_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_integer_64: {
        std::stringstream ss;
        ss << "modulus_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_unsigned_integer_64: {
        std::stringstream ss;
        ss << "modulus_unsigned_integer_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_float_32: {
        std::stringstream ss;
        ss << "modulus_float_32: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::modulus_float_64: {
        std::stringstream ss;
        ss << "modulus_float_64: ";
        size_t offset = 1;
        ss << *(size_t*)(ptr + offset);
        ss << ", ";
        offset += sizeof(size_t);
        ss << *(size_t*)(ptr + offset);
        offset += sizeof(size_t);
        return std::move(ss.str());
    }
    case codes::signal: {
        std::stringstream ss;
        ss << "signal: ";
        size_t offset = 1;
        ss << *(const char**)(ptr + offset);
        offset += sizeof(const char*);
        return std::move(ss.str());
    }
    default: {
        throw std::runtime_error("Invalid command code:" + std::to_string((int)*ptr));
    }
}
}