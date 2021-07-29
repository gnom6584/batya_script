//
// Created by Name on 24.07.2021.
//

#include "common_type.hpp"

#include <utility>

using namespace batya_script::ast::typing;

CommonType::CommonType(std::string name, size_t size) noexcept(true) : _name(std::move(name)), _size(size) {}


std::string_view CommonType::name() const noexcept(true) {
	return _name;
}


void CommonType::add_binary_operator(std::string sign, BinaryOperator binary_operator) noexcept(true) {
	_binary_operators.emplace(std::move(sign), binary_operator);
}


void CommonType::add_unary_operator(std::string sign, UnaryOperator unary_operator) noexcept(true) {
	_unary_operators.emplace(std::move(sign), unary_operator);
}


size_t CommonType::size() const noexcept(true) {
	return _size;
}
