//
// Created by Name on 27.07.2021.
//

#include "unary_operator.hpp"


batya_script::ast::typing::UnaryOperator::UnaryOperator(const batya_script::ast::typing::Type& return_type, const batya_script::ast::typing::Type& operand_type)
	: _return_type(return_type), _operand_type(operand_type) {

}


const batya_script::ast::typing::Type& batya_script::ast::typing::UnaryOperator::return_type() const noexcept(true) {
	return _return_type;
}


const batya_script::ast::typing::Type& batya_script::ast::typing::UnaryOperator::operand_type() const noexcept(true) {
	return _operand_type;
}
