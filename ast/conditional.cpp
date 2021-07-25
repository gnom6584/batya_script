//
// Created by Name on 24.07.2021.
//

#include "conditional.hpp"
#include "typing/built_in_types_container.hpp"
#include "stdexcept"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace typing;
using namespace utility;


Conditional::Conditional(SinglePointer<Expression> bool_expression, SinglePointer<Expression> on_true, optional<SinglePointer<Expression>> on_false) noexcept(false)
	:
	Expression(on_false.has_value() ? on_true->result_type() : BuiltInTypesContainer::instance().nothing()),
	_bool_expression(move(bool_expression)), _on_true_expression(move(on_true)), _on_false_expression(move(on_false)) {

	if(on_false.has_value() && on_false.value()->result_type() != on_true->result_type())
		throw runtime_error("Type of true, false branches is not equal");
}


const Expression& Conditional::bool_expression() const noexcept(true) {
	return *_bool_expression;
}


const Expression& Conditional::on_true_expression() const noexcept(true) {
	return *_on_true_expression;
}


const Expression& Conditional::on_false_expression() const noexcept(false) {
	if(!_on_false_expression.has_value())
		throw runtime_error("On false expression is not assigned!");
	return *_on_false_expression.value();
}


bool Conditional::has_expression() const noexcept(true) {
	return _on_false_expression.has_value();
}
