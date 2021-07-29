//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_BINARY_OPERATOR_HPP_
#define BATYA_SCRIPT_AST_BINARY_OPERATOR_HPP_

#include <string>
#include "../utility/single_pointer.hpp"
#include "expression.hpp"

namespace batya_script::ast {

class BinaryOperator : public Expression {
public:

	BinaryOperator(const typing::Type& result_type, std::string sign, utility::SinglePointer<Expression> left_operand, utility::SinglePointer<Expression> right_operand) noexcept(true);

	[[nodiscard]] const Expression& left_operand() const noexcept(true);

	[[nodiscard]] const Expression& right_operand() const noexcept(true);

private:

	std::string _sign;

	utility::SinglePointer<Expression> _left_operand;

	utility::SinglePointer<Expression> _right_operand;
};

}

#endif //BATYA_SCRIPT_AST_BINARY_OPERATOR_HPP_
