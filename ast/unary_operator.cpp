//
// Created by Name on 27.07.2021.
//

#include "unary_operator.hpp"
#include <utility>

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace utility;
using namespace typing;

UnaryOperator::UnaryOperator(std::string sign, const typing::Type& result_type, utility::SinglePointer<Expression> operand) noexcept(true)
	: Expression(result_type), _sign(move(sign)), _operand(move(operand)){

}


const string& UnaryOperator::sign() const noexcept(true) {
	return _sign;
}


const Expression& UnaryOperator::operand() const noexcept(true) {
	return *_operand;
}
