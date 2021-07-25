//
// Created by Name on 24.07.2021.
//

#include "common_type.hpp"

#include <utility>

using namespace batya_script::ast::typing;

CommonType::CommonType(std::string name) noexcept(true) : _name(std::move(name)) {}


std::string_view CommonType::name() const noexcept(true) {
	return _name;
}
