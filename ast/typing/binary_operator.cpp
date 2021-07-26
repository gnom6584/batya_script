//
// Created by Name on 26.07.2021.
//

#include "binary_operator.hpp"


batya_script::ast::typing::BinaryOperator::BinaryOperator(const batya_script::ast::typing::Type& return_type, const batya_script::ast::typing::Type& left_operand_type, const batya_script::ast::typing::Type& right_operand_type,  int precedence)
	: _return_type(return_type), _left_operand_type(left_operand_type), _right_operand_type(right_operand_type), _precedence(precedence) {}


const batya_script::ast::typing::Type& batya_script::ast::typing::BinaryOperator::return_type() const noexcept(true) {
	return _return_type;
}


const batya_script::ast::typing::Type& batya_script::ast::typing::BinaryOperator::left_operand_type() const noexcept(true) {
	return _left_operand_type;
}


const batya_script::ast::typing::Type& batya_script::ast::typing::BinaryOperator::right_operand_type() const noexcept(true) {
	return _right_operand_type;
}


int batya_script::ast::typing::BinaryOperator::precedence() const noexcept(true) {
	return _precedence;
}
