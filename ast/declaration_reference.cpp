//
// Created by Name on 26.07.2021.
//

#include "declaration_reference.hpp"


batya_script::ast::DeclarationReference::DeclarationReference(const typing::Type& type, std::vector<std::string> members, size_t offset) noexcept(true)
	: Expression(type), _members(move(members)), _type(type), _offset(offset) {

}


const std::vector<std::string>& batya_script::ast::DeclarationReference::members() const noexcept(true) {
	return _members;
}


const size_t batya_script::ast::DeclarationReference::offset() const noexcept(true) {
	return _offset;
}
