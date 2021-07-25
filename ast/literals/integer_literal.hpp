//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_LITERALS_INTEGER_LITERAL_HPP_
#define BATYA_SCRIPT_AST_LITERALS_INTEGER_LITERAL_HPP_

#include "literal.hpp"

namespace batya_script::ast::literals {

class IntegerLiteral : public Literal {
public:
	explicit IntegerLiteral(int value) noexcept(true);

private:
	int _value;

};

}

#endif //BATYA_SCRIPT_AST_LITERALS_INTEGER_LITERAL_HPP_
