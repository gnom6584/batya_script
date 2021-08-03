//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_ASSIGNMENT_HPP_
#define BATYA_SCRIPT_AST_ASSIGNMENT_HPP_

#include "expression.hpp"

#include "declarations/variable_declaration.hpp"
#include "declaration_reference.hpp"

namespace batya_script::ast {

class Assignment : public Expression {
public:
	Assignment(batya_script::utility::SinglePointer<Expression> declaration, batya_script::utility::SinglePointer<Expression> assignment_expression) noexcept(false);

	[[nodiscard]] const DeclarationReference& declaration() const noexcept(true);

	[[nodiscard]] const Expression& assignment_expression() const noexcept(true);

private:
	const batya_script::utility::SinglePointer<Expression> _declaration;

	const batya_script::utility::SinglePointer<Expression> _assignment_expression;
};

}

#endif //BATYA_SCRIPT_AST_ASSIGNMENT_HPP_
