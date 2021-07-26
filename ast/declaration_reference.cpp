//
// Created by Name on 26.07.2021.
//

#include "declaration_reference.hpp"


batya_script::ast::DeclarationReference::DeclarationReference(const batya_script::ast::declarations::VariableDeclaration& variable_declaration) noexcept(true)
	: Expression(variable_declaration.result_type()), _variable_declaration(variable_declaration) {

}


const batya_script::ast::declarations::VariableDeclaration& batya_script::ast::DeclarationReference::variable_declaration() const noexcept(true) {
	return _variable_declaration;
}
