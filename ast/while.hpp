//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_WHILE_HPP_
#define BATYA_SCRIPT_AST_WHILE_HPP_

#include "expression.hpp"
#include "../utility/single_pointer.hpp"

namespace batya_script::ast {

class While : public Expression {
public:
	While(utility::SinglePointer<Expression> condition, utility::SinglePointer<Expression> body) noexcept(false);

	[[nodiscard]] const Expression& condition() const noexcept(true);

	[[nodiscard]] const Expression& body() const noexcept(true);

private:
	utility::SinglePointer<Expression> _condition;

	utility::SinglePointer<Expression> _body;
};

}

#endif //BATYA_SCRIPT_AST_WHILE_HPP_
