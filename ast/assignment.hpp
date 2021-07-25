//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_ASSIGNMENT_HPP_
#define BATYA_SCRIPT_AST_ASSIGNMENT_HPP_

#include "expression.hpp"

#include "declarations/variable_declaration.hpp"

namespace batya_script::ast {

class Assignment : public Expression {
public:
	Assignment(const declarations::VariableDeclaration& declaration, batya_script::utility::SinglePointer<Expression> assignment_expression) noexcept(false);

	[[nodiscard]] const declarations::VariableDeclaration& declaration() const noexcept(true);

	[[nodiscard]] const Expression& assignment_expression() const noexcept(true);

private:
	const declarations::VariableDeclaration& _declaration;

	const batya_script::utility::SinglePointer<Expression> _assignment_expression;
};

}

#endif //BATYA_SCRIPT_AST_ASSIGNMENT_HPP_
