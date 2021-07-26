//
// Created by Name on 24.07.2021.
//

#include "common_type.hpp"

#include <utility>

using namespace batya_script::ast::typing;

CommonType::CommonType(std::string name, std::vector<BinaryOperator> binary_operators) noexcept(true) : _name(std::move(name)), _binary_operators(std::move(binary_operators)) {}


std::string_view CommonType::name() const noexcept(true) {
	return _name;
}
