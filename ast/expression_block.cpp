//
// Created by Name on 24.07.2021.
//

#include "expression_block.hpp"


batya_script::ast::ExpressionBlock::ExpressionBlock(const batya_script::ast::typing::Type& type) : Expression(type) {

}


void batya_script::ast::ExpressionBlock::add(batya_script::utility::SinglePointer<Expression> expression) noexcept(true) {
	_children.emplace_back(std::move(expression));
}


const batya_script::ast::Expression& batya_script::ast::ExpressionBlock::operator[](size_t index) const noexcept(false) {
	return *_children.at(index);
}
