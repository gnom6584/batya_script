//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATIONS_VARIABLE_DECLARATION_HPP_
#define BATYA_SCRIPT_AST_DECLARATIONS_VARIABLE_DECLARATION_HPP_

#include <optional>
#include "../../utility/single_pointer.hpp"

#include "declaration.hpp"

namespace batya_script::ast::declarations {

class VariableDeclaration : public Declaration {
public:
	VariableDeclaration(const typing::Type& type, std::string name, std::optional<batya_script::utility::SinglePointer<Expression>> assignment = {}) noexcept(false);

	[[nodiscard]] const std::string& name() const noexcept(true);

	[[nodiscard]] const Expression& assignment() const noexcept(false);

	[[nodiscard]] bool has_assignment() const noexcept(true);

private:
	std::string _name;
	std::optional<batya_script::utility::SinglePointer<Expression>> _assignment;
};

}

#endif //BATYA_SCRIPT_AST_DECLARATIONS_VARIABLE_DECLARATION_HPP_
