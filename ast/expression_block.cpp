//
// Created by Name on 24.07.2021.
//

#include "expression_block.hpp"


batya_script::ast::ExpressionBlock::ExpressionBlock(const batya_script::ast::typing::Type& type, std::vector<batya_script::utility::SinglePointer<Expression>> children) noexcept(true)
	: Expression(type), _children(std::move(children)) {

}


const batya_script::ast::Expression& batya_script::ast::ExpressionBlock::get(size_t index) const noexcept(false) {
	return *_children.at(index);
}


size_t batya_script::ast::ExpressionBlock::min_index() const {
	return 0;
}


size_t batya_script::ast::ExpressionBlock::max_index() const {
	return _children.empty() ? 0 : _children.size() - 1;
}
