//
// Created by Name on 03.08.2021.
//

#include "struct_declaration.hpp"
#include "../typing/built_in_types_container.hpp"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace declarations;

StructDeclaration::StructDeclaration(std::string name, std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> fields) noexcept(true)
	: Declaration(typing::BuiltInTypesContainer::instance().nothing()), _name(move(name)), _fields(move(fields))
	{}


const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>>& StructDeclaration::fields() const noexcept(true) {
	return _fields;
}


const string& declarations::StructDeclaration::name() const noexcept(true) {
	return _name;
}