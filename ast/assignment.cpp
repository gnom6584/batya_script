//
// Created by Name on 24.07.2021.
//

#include "assignment.hpp"

using namespace batya_script::ast;
using namespace declarations;

Assignment::Assignment(const declarations::VariableDeclaration& declaration, batya_script::utility::SinglePointer<Expression> assignment_expression) noexcept(false)
	: Expression(declaration.result_type()), _declaration(declaration), _assignment_expression(std::move(assignment_expression)) {
	if(declaration.result_type() != assignment_expression->result_type()) {

	}

}


const VariableDeclaration& Assignment::declaration() const noexcept(true){
	return _declaration;
}


const Expression& Assignment::assignment_expression() const noexcept(true) {
	return *_assignment_expression;
}
