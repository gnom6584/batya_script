//
// Created by Name on 23.07.2021.
//

#include "type.hpp"


bool batya_script::ast::typing::Type::operator==(const batya_script::ast::typing::Type& right) const noexcept(true) {
	return right.name() == name();
}


bool batya_script::ast::typing::Type::operator!=(const batya_script::ast::typing::Type& right) const noexcept(true) {
	return right.name() != name();
}
