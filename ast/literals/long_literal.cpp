//
// Created by Name on 02.08.2021.
//

#include "long_literal.hpp"
#include "../typing/built_in_types_container.hpp"


batya_script::ast::literals::UnsignedInteger8Literal::UnsignedInteger8Literal(unsigned long long int value) noexcept(true)
	: Literal(typing::BuiltInTypesContainer::instance().unsigned_integer_8()), _value(value) {

}


unsigned long long int batya_script::ast::literals::UnsignedInteger8Literal::value() const noexcept(true) {
	return _value;
}
