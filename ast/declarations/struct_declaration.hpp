//
// Created by Name on 03.08.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATIONS_STRUCT_DECLARATION_HPP_
#define BATYA_SCRIPT_AST_DECLARATIONS_STRUCT_DECLARATION_HPP_

#include <vector>
#include <functional>
#include <utility>

#include "declaration.hpp"
#include "variable_declaration.hpp"
#include "../typing/common_type.hpp"

namespace batya_script::ast::declarations {

class StructDeclaration : public Declaration {
public:
	explicit StructDeclaration(std::string name, std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> fields) noexcept(true);

	[[nodiscard]] const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>>& fields() const noexcept(true);

	[[nodiscard]] const std::string& name() const noexcept(true);

private:

	std::string _name;

	std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> _fields;
};

}

#endif //BATYA_SCRIPT_AST_DECLARATIONS_STRUCT_DECLARATION_HPP_
