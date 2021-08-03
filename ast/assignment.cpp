//
// Created by Name on 24.07.2021.
//

#include "assignment.hpp"

#include <stdexcept>

using namespace batya_script::ast;
using namespace declarations;

Assignment::Assignment(batya_script::utility::SinglePointer<Expression> declaration, batya_script::utility::SinglePointer<Expression> assignment_expression) noexcept(false)
	: Expression(declaration->result_type()), _declaration(std::move(declaration)), _assignment_expression(std::move(assignment_expression)) {
	if(_declaration->result_type() != _assignment_expression->result_type())
		throw std::runtime_error("Invalid types for assigment");

}


const DeclarationReference& Assignment::declaration() const noexcept(true){
	return dynamic_cast<const DeclarationReference&>(*_declaration);
}


const Expression& Assignment::assignment_expression() const noexcept(true) {
	return *_assignment_expression;
}
