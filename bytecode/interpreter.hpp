//
// Created by Name on 20.07.2021.
//

#ifndef BATYA_SCRIPT_BYTECODE_INTERPRETER_HPP_
#define BATYA_SCRIPT_BYTECODE_INTERPRETER_HPP_

#include <vector>
#include "stack.hpp"

namespace batya_script::bytecode {

class Interpreter {
public:

	explicit Interpreter(size_t stack_size_bytes) noexcept(true);

	static void run(const std::vector<unsigned char>& bytecode, Stack& stack, std::stack<size_t>& headers) noexcept(false);

private:
	Stack _stack;
};

}

#endif //BATYA_SCRIPT_BYTECODE_INTERPRETER_HPP_
