//
// Created by Name on 26.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_BINARY_OPERATOR_HPP_
#define BATYA_SCRIPT_AST_TYPING_BINARY_OPERATOR_HPP_

#include "type.hpp"

namespace batya_script::ast::typing {

class BinaryOperator final {
public:

	BinaryOperator(const Type& return_type, const Type& left_operand_type, const Type& right_operand_type, int precedence);

	[[nodiscard]] const Type& return_type() const noexcept(true);

	[[nodiscard]] const Type& left_operand_type() const noexcept(true);

	[[nodiscard]] const Type& right_operand_type() const noexcept(true);

	[[nodiscard]] int precedence() const noexcept(true);

private:
	const Type& _return_type;

	const Type& _left_operand_type;

	const Type& _right_operand_type;

	int _precedence;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_BINARY_OPERATOR_HPP_
