//
// Created by Name on 24.07.2021.
//

#include "common_type.hpp"

#include <utility>

using namespace batya_script::ast::typing;

CommonType::CommonType(std::string name, size_t size, std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> fields) noexcept(true)
	: _name(std::move(name)), _size(size), _fields(std::move(fields)) {}


const std::vector<std::pair<std::string, std::reference_wrapper<const Type>>>& CommonType::fields() const noexcept(true) {
	return _fields;
}

std::string_view CommonType::name() const noexcept(true) {
	return _name;
}


size_t CommonType::size() const noexcept(true) {
	return _size;
}
