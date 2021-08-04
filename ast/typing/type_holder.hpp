//
// Created by Name on 04.08.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_TYPE_HOLDER_HPP_
#define BATYA_SCRIPT_AST_TYPING_TYPE_HOLDER_HPP_

#include "type.hpp"

namespace batya_script::ast::typing {

class TypeHolder {
public:
	explicit TypeHolder(const Type& type) noexcept(true);
};

}

#endif //BATYA_SCRIPT_AST_TYPING_TYPE_HOLDER_HPP_
