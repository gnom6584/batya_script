//
// Created by Name on 26.07.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_
#define BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_

#include "expression.hpp"
#include "declarations/variable_declaration.hpp"

namespace batya_script::ast {

class DeclarationReference : public Expression {
public:

	explicit DeclarationReference(const declarations::VariableDeclaration& variable_declaration) noexcept(true);

	[[nodiscard]] const declarations::VariableDeclaration& variable_declaration() const noexcept(true);

private:
	const declarations::VariableDeclaration& _variable_declaration;
};

}

#endif //BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_
