//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_
#define BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_

#include "../utility/single_pointer.hpp"
#include "../utility/indexed_container.hpp"
#include <vector>
#include "expression.hpp"

namespace batya_script::ast {

class ExpressionBlock : public Expression, public utility::IndexedContainer<Expression> {
public:

	ExpressionBlock(const typing::Type& type, std::vector<batya_script::utility::SinglePointer<Expression>> children) noexcept(true);

	[[nodiscard]] const Expression& get(size_t index) const noexcept(false) override;

private:
	std::vector<batya_script::utility::SinglePointer<Expression>> _children;
};

}

#endif //BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_
