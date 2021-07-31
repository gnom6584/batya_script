//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_CONDITION_HPP_
#define BATYA_SCRIPT_AST_CONDITION_HPP_

#include "expression.hpp"

#include <optional>
#include "../utility/single_pointer.hpp"

namespace batya_script::ast {

class Condition : public Expression {
public:
	explicit Condition(batya_script::utility::SinglePointer<Expression> bool_expression, batya_script::utility::SinglePointer<Expression> on_true, std::optional<batya_script::utility::SinglePointer<Expression>> on_false = {}) noexcept(false);

	[[nodiscard]] const Expression& bool_expression() const noexcept(true);

	[[nodiscard]] const Expression& on_true_expression() const noexcept(true);

	[[nodiscard]] const Expression& on_false_expression() const noexcept(false);

	[[nodiscard]] bool has_on_false_expression() const noexcept(true);

private:

	const batya_script::utility::SinglePointer<Expression> _bool_expression;

	const batya_script::utility::SinglePointer<Expression> _on_true_expression;

	const std::optional<batya_script::utility::SinglePointer<Expression>> _on_false_expression;


};

}

#endif //BATYA_SCRIPT_AST_CONDITION_HPP_
