//
// Created by Name on 24.07.2021.
//

#include "while.hpp"
#include "typing/built_in_types_container.hpp"

#include <stdexcept>

using namespace std;

using namespace batya_script;
using namespace ast;
using namespace utility;
using namespace typing;


While::While(SinglePointer<batya_script::ast::Expression> condition,SinglePointer<Expression> body) noexcept(false)
	: Expression(BuiltInTypesContainer::instance().nothing()), _body(move(body)), _condition(move(condition)) {
		if(_condition->result_type() != BuiltInTypesContainer::instance().boolean())
			throw runtime_error("Condition is not condition!");
}


const Expression& While::condition() const noexcept(true) {
	return *_condition;
}


const Expression& While::body() const noexcept(true) {
	return *_body;
}
