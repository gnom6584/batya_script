#include <iostream>
#include <cstring>
#include <stack>
#include <map>

#include "bytecode/bytecode_builder.hpp"
#include "bytecode/interpreter.hpp"
#include "bytecode/codes.hpp"
int main() {
	using namespace batya_script::bytecode;
	BytecodeBuilder b;
	const char* sig = "abvgd\n";
	Stack stack(100);

	b.stack_allocate(4);
	b.set_integer_32(0, 10);
	b.stack_allocate(4);
	b.set_integer_32(4, 1);
	b.stack_allocate(4);
	b.set_integer_32(8, 0);
	b.stack_allocate(1);

	auto label = b.position();
	b.signal((size_t)sig);
	b.equal_32(8, 0, 12);
	b.add_integer_32(8, 4);
	b.go_to_if(12, label);
	auto bytecode = b.build();


	Interpreter::run(bytecode, stack);
	return 0;
}
