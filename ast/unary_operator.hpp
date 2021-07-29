//
// Created by Name on 27.07.2021.
//

#ifndef BATYA_SCRIPT_AST_UNARY_OPERATOR_HPP_
#define BATYA_SCRIPT_AST_UNARY_OPERATOR_HPP_

#include "expression.hpp"
#include "../utility/single_pointer.hpp"

namespace batya_script::ast {

class UnaryOperator : public Expression {
public:

	UnaryOperator(std::string sign, const typing::Type& result_type, utility::SinglePointer<Expression> operand) noexcept(true);

	[[nodiscard]] const std::string& sign() const noexcept(true);

	[[nodiscard]] const Expression& operand() const noexcept(true);

private:

	std::string _sign;

	utility::SinglePointer<Expression> _operand;
};

}
#endif //BATYA_SCRIPT_AST_UNARY_OPERATOR_HPP_
