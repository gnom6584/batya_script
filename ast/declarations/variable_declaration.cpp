//
// Created by Name on 24.07.2021.
//

#include "variable_declaration.hpp"

#include <stdexcept>

using namespace std;
using namespace batya_script::ast;
using namespace declarations;

VariableDeclaration::VariableDeclaration(const batya_script::ast::typing::Type& type, std::string name, std::optional<batya_script::utility::SinglePointer<Expression>> assignment) noexcept(false)
	: Declaration(type), _name(move(name)), _assignment(move(assignment)) {
	if(assignment.has_value() && assignment.value()->result_type() != type)
		throw runtime_error("Invalid assignment type!");
}


const std::string& VariableDeclaration::name() const noexcept(true) {
	return _name;
}


const Expression& VariableDeclaration::assignment() const noexcept(false) {
	if(!_assignment.has_value())
		throw std::runtime_error("Variable declaration assignment is not assigned!");
	return *_assignment.value();
}


bool declarations::VariableDeclaration::has_assignment() const noexcept(true) {
	return _assignment.has_value();
}
