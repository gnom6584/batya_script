//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_EXPRESSION_HPP_
#define BATYA_SCRIPT_AST_EXPRESSION_HPP_

#include "typing/type.hpp"

namespace batya_script::ast {

class Expression {
public:

	explicit Expression(const typing::Type& result_type) noexcept(true);

	virtual ~Expression() = default;

	[[nodiscard]] const typing::Type& result_type() const noexcept(true);

private:
	const typing::Type& _result_type;
};

}

#endif //BATYA_SCRIPT_AST_EXPRESSION_HPP_
