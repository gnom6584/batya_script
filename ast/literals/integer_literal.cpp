//
// Created by Name on 24.07.2021.
//

#include "integer_literal.hpp"
#include "../typing/built_in_types_container.hpp"

using namespace batya_script::ast::literals;

IntegerLiteral::IntegerLiteral(int value) noexcept(true) : Literal(typing::BuiltInTypesContainer::instance().integer()), _value(value) {

}
