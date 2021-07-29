//
// Created by Name on 27.07.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATIONS_FUNCTION_DECLARATION_HPP_
#define BATYA_SCRIPT_AST_DECLARATIONS_FUNCTION_DECLARATION_HPP_

#include <vector>
#include "../expression.hpp"

namespace batya_script::ast::declarations {

class FunctionDeclaration : public Expression {
public:
	FunctionDeclaration(std::string name, std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> parameters, const typing::Type& return_type) noexcept(false);

	[[nodiscard]] const std::string& name() const noexcept(true);

	[[nodiscard]] const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>>& parameters() const noexcept(true);

	[[nodiscard]] const typing::Type& return_type() const noexcept(true);

private:
	const std::string _name;

	const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> _parameters;

	const typing::Type& _return_type;
};

}

#endif //BATYA_SCRIPT_AST_DECLARATIONS_FUNCTION_DECLARATION_HPP_