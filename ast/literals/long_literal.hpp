//
// Created by Name on 02.08.2021.
//

#ifndef BATYA_SCRIPT_AST_LITERALS_LONG_LITERAL_HPP_
#define BATYA_SCRIPT_AST_LITERALS_LONG_LITERAL_HPP_

#include "literal.hpp"

namespace batya_script::ast::literals {

class UnsignedInteger8Literal : public Literal {
public:
	explicit UnsignedInteger8Literal(unsigned long long int value) noexcept(true);

	[[nodiscard]] unsigned long long int value() const noexcept(true);

private:
	unsigned long long int _value;

};
}

#endif //BATYA_SCRIPT_AST_LITERALS_LONG_LITERAL_HPP_
