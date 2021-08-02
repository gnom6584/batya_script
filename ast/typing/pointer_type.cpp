//
// Created by Name on 01.08.2021.
//

#include "pointer_type.hpp"


batya_script::ast::typing::PointerType::PointerType(const batya_script::ast::typing::CommonType& type) noexcept(true)
	: _type(type), _name(std::string(_type.name()) + "*") {

}


size_t batya_script::ast::typing::PointerType::size() const noexcept(true) {
	return sizeof(uintptr_t);
}


std::string_view batya_script::ast::typing::PointerType::name() const noexcept(true) {
	return _name;
}
