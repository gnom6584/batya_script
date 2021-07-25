//
// Created by Name on 24.07.2021.
//

#include "built_in_types_container.hpp"

using namespace batya_script::ast::typing;

BuiltInTypesContainer::BuiltInTypesContainer() noexcept(true) :
	_nothing(CommonType("Nothing")),
	_boolean(CommonType("Boolean")),
	_integer(CommonType("Integer"))
	{}


const Type& BuiltInTypesContainer::nothing() const {
	return _nothing;
}


const Type& BuiltInTypesContainer::boolean() const {
	return _boolean;
}


const BuiltInTypesContainer& BuiltInTypesContainer::instance() noexcept(true) {
	const static auto instance =  BuiltInTypesContainer();
	return instance;
}


const Type& BuiltInTypesContainer::integer() const {
	return _integer;
}
