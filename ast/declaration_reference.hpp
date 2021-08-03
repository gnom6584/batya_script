//
// Created by Name on 26.07.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_
#define BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_

#include <vector>
#include "expression.hpp"
#include "declarations/variable_declaration.hpp"

namespace batya_script::ast {

class DeclarationReference : public Expression {
public:

	explicit DeclarationReference(const typing::Type& type, std::vector<std::string> members, size_t offset) noexcept(true);

	[[nodiscard]] const std::vector<std::string>& members() const noexcept(true);

	[[nodiscard]] const size_t offset() const noexcept(true);

private:
	const std::vector<std::string> _members;

	const size_t _offset;

	const typing::Type& _type;
};

}

#endif //BATYA_SCRIPT_AST_DECLARATION_REFERENCE_HPP_
