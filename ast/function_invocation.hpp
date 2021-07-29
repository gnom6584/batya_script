//
// Created by Name on 27.07.2021.
//

#ifndef BATYA_SCRIPT_AST_FUNCTION_INVOCATION_HPP_
#define BATYA_SCRIPT_AST_FUNCTION_INVOCATION_HPP_

#include <vector>
#include "expression.hpp"
#include "declarations/function_declaration.hpp"
#include "../utility/single_pointer.hpp"

namespace batya_script::ast {

class FunctionInvocation : public Expression {
public:
	FunctionInvocation(const declarations::FunctionDeclaration& declaration, std::vector<utility::SinglePointer<Expression>> args) noexcept(false);

	[[nodiscard]] const std::vector<utility::SinglePointer<Expression>>& arguments() const noexcept(true) ;

	[[nodiscard]] const declarations::FunctionDeclaration& declaration() const noexcept(true) ;

private:

	std::vector<utility::SinglePointer<Expression>> _arguments;

	const declarations::FunctionDeclaration& _declaration;
};

}

#endif //BATYA_SCRIPT_AST_FUNCTION_INVOCATION_HPP_
