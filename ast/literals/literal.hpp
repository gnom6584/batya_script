//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_LITERALS_LITERAL_HPP_
#define BATYA_SCRIPT_AST_LITERALS_LITERAL_HPP_

#include "../expression.hpp"

namespace batya_script::ast::literals {

class Literal : public Expression {
protected:
	explicit Literal(const typing::Type& type) noexcept(true);
};

}

#endif //BATYA_SCRIPT_AST_LITERALS_LITERAL_HPP_
