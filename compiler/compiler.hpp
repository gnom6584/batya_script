//
// Created by Name on 28.07.2021.
//

#ifndef BATYA_SCRIPT_COMPILER_COMPILER_HPP_
#define BATYA_SCRIPT_COMPILER_COMPILER_HPP_

#include "../bytecode/bytecode_builder.hpp"
#include <string>

namespace batya_script {

class Compiler {
public:
	[[nodiscard]] static bytecode::Bytecode compile(const std::string& str);
};

}

#endif //BATYA_SCRIPT_COMPILER_COMPILER_HPP_
