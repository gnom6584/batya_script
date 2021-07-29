//
// Created by Name on 27.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_UNARY_OPERATOR_HPP_
#define BATYA_SCRIPT_AST_TYPING_UNARY_OPERATOR_HPP_

#include "type.hpp"

namespace batya_script::ast::typing {

class UnaryOperator {
public:

	UnaryOperator(const Type& return_type, const Type& operand_type);

	[[nodiscard]] const Type& return_type() const noexcept(true);

	[[nodiscard]] const Type& operand_type() const noexcept(true);

private:
	const Type& _return_type;

	const Type& _operand_type;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_UNARY_OPERATOR_HPP_
