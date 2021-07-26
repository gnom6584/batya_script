//
// Created by Name on 24.07.2021.
//

#include "binary_operator.hpp"

#include <utility>

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace utility;


BinaryOperator::BinaryOperator(const typing::Type& result_type, std::string sign, SinglePointer<Expression> left_operand, SinglePointer<Expression> right_operand) noexcept(true)
	: Expression(result_type), _sign(std::move(sign)), _left_operand(move(left_operand)), _right_operand(move(right_operand)) {



}


const Expression& BinaryOperator::left_operand() const noexcept(true) {
	return *_left_operand;
}


const Expression& BinaryOperator::right_operand() const noexcept(true) {
	return *_right_operand;
}
