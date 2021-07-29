//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_LITERALS_BOOLEAN_LITERAL_HPP_
#define BATYA_SCRIPT_AST_LITERALS_BOOLEAN_LITERAL_HPP_

#include "literal.hpp"

namespace batya_script::ast::literals {

class BooleanLiteral : public Literal {
public:

	explicit BooleanLiteral(bool value) noexcept(true);

	[[nodiscard]] bool value() const noexcept(true);

private:

	bool _value;

};

}

#endif //BATYA_SCRIPT_AST_LITERALS_BOOLEAN_LITERAL_HPP_
