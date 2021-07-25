//
// Created by Name on 24.07.2021.
//

#include "literal.hpp"

using namespace batya_script::ast;
using namespace typing;
using namespace literals;

Literal::Literal(const Type& type) noexcept(true)
	: Expression(type) {

}
