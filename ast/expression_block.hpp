//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_
#define BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_

#include "../utility/single_pointer.hpp"
#include <vector>
#include "expression.hpp"

namespace batya_script::ast {

class ExpressionBlock : public Expression {
public:

	explicit ExpressionBlock(const typing::Type& type);

	void add(batya_script::utility::SinglePointer<Expression> expression) noexcept(true);

	[[nodiscard]] const Expression& operator[](size_t index) const noexcept(false);

private:
	std::vector<batya_script::utility::SinglePointer<Expression>> _children;
};

}

#endif //BATYA_SCRIPT_AST_EXPRESSION_BLOCK_HPP_
