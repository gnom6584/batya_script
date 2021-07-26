//
// Created by Name on 24.07.2021.
//

#include "condition.hpp"
#include "typing/built_in_types_container.hpp"
#include "stdexcept"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace typing;
using namespace utility;


Condition::Condition(SinglePointer<Expression> bool_expression, SinglePointer<Expression> on_true, optional<SinglePointer<Expression>> on_false) noexcept(false)
	:
	Expression(on_false.has_value() ? on_true->result_type() : BuiltInTypesContainer::instance().nothing()),
	_bool_expression(move(bool_expression)), _on_true_expression(move(on_true)), _on_false_expression(move(on_false)) {

	if(_bool_expression->result_type() != BuiltInTypesContainer::instance().boolean())
		throw runtime_error("Condition is not condition!");

	if(_on_false_expression.has_value() && _on_false_expression.value()->result_type() != _on_true_expression->result_type())
		throw runtime_error("Types of branches is not equal");
}


const Expression& Condition::bool_expression() const noexcept(true) {
	return *_bool_expression;
}


const Expression& Condition::on_true_expression() const noexcept(true) {
	return *_on_true_expression;
}


const Expression& Condition::on_false_expression() const noexcept(false) {
	if(!_on_false_expression.has_value())
		throw runtime_error("On false expression is not assigned!");
	return *_on_false_expression.value();
}


bool Condition::has_expression() const noexcept(true) {
	return _on_false_expression.has_value();
}
