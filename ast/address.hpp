//
// Created by Name on 01.08.2021.
//

#ifndef BATYA_SCRIPT_AST_ADDRESS_HPP_
#define BATYA_SCRIPT_AST_ADDRESS_HPP_

#include "expression.hpp"

#include "declaration_reference.hpp"

namespace batya_script::ast {

class Address : public Expression {
public:
	explicit Address(utility::SinglePointer<Expression> reference) noexcept(true);

	[[nodiscard]] const DeclarationReference& declaration_reference() const noexcept(true);
private:
	utility::SinglePointer<Expression> _reference;
};

}

#endif //BATYA_SCRIPT_AST_ADDRESS_HPP_
