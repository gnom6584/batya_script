//
// Created by Name on 24.07.2021.
//

#include "boolean_literal.hpp"
#include "../typing/built_in_types_container.hpp"

using namespace batya_script::ast::literals;

BooleanLiteral::BooleanLiteral(bool value) noexcept(true)
	: Literal(typing::BuiltInTypesContainer::instance().boolean()), _value(value) {

}
