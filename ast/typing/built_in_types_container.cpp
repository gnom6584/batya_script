//
// Created by Name on 24.07.2021.
//

#include "built_in_types_container.hpp"
#include "../../resources/keywords/keys.hpp"
#include "../../resources/keywords/keywords.hpp"

using namespace batya_script::ast::typing;
using namespace batya_script::resources::keywords;

BuiltInTypesContainer::BuiltInTypesContainer() noexcept(true) :
	_nothing(CommonType(get_key_spelling(Key::Nothing), 0)),
	_boolean(CommonType(get_key_spelling(Key::Boolean), 1)),
	_integer_1(CommonType(get_key_spelling(Key::Integer_1), 1)),
	_unsigned_integer_1(CommonType(get_key_spelling(Key::Unsigned_integer_1), 1)),
	_integer_2(CommonType(get_key_spelling(Key::Integer_2), 2)),
	_unsigned_integer_2(CommonType(get_key_spelling(Key::Unsigned_integer_2), 2)),
	_integer_4(CommonType(get_key_spelling(Key::Integer_4), 4)),
	_unsigned_integer_4(CommonType(get_key_spelling(Key::Unsigned_integer_4), 4)),
	_integer_8(CommonType(get_key_spelling(Key::Integer_8), 8)),
	_unsigned_integer_8(CommonType(get_key_spelling(Key::Unsigned_integer_8), 8)),
	_float_4(CommonType(get_key_spelling(Key::Float_4), 4)),
	_float_8(CommonType(get_key_spelling(Key::Float_8), 8)),
	_nothing_ptr(_nothing),
	_boolean_ptr(_boolean),
	_integer_1_ptr(_integer_1),
	_unsigned_integer_1_ptr(_unsigned_integer_1),
	_integer_2_ptr(_integer_2),
	_unsigned_integer_2_ptr(_unsigned_integer_2),
	_integer_4_ptr(_integer_4),
	_unsigned_integer_4_ptr(_unsigned_integer_4),
	_integer_8_ptr(_integer_8),
	_unsigned_integer_8_ptr(_unsigned_integer_8),
	_float_4_ptr(_float_4),
	_float_8_ptr(_float_8)
	{
	}


const BuiltInTypesContainer& BuiltInTypesContainer::instance() noexcept(true) {
	const static auto instance =  BuiltInTypesContainer();
	return instance;
}


const Type& BuiltInTypesContainer::nothing() const noexcept(true) {
	return _nothing;
}


const Type& BuiltInTypesContainer::boolean() const noexcept(true) {
	return _boolean;
}


const Type& BuiltInTypesContainer::integer_1() const noexcept(true) {
	return _integer_1;
}


const Type& BuiltInTypesContainer::unsigned_integer_1() const noexcept(true) {
	return _unsigned_integer_1;
}


const Type& BuiltInTypesContainer::integer_2() const noexcept(true) {
	return _integer_2;
}


const Type& BuiltInTypesContainer::unsigned_integer_2() const noexcept(true) {
	return _unsigned_integer_2;
}


const Type& BuiltInTypesContainer::integer_4() const noexcept(true) {
	return _integer_4;
}


const Type& BuiltInTypesContainer::unsigned_integer_4() const noexcept(true) {
	return _unsigned_integer_4;
}


const Type& BuiltInTypesContainer::integer_8() const noexcept(true) {
	return _integer_8;
}


const Type& BuiltInTypesContainer::unsigned_integer_8() const noexcept(true) {
	return _unsigned_integer_8;
}


const Type& BuiltInTypesContainer::float_4() const noexcept(true) {
	return _float_4;
}


const Type& BuiltInTypesContainer::float_8() const noexcept(true) {
	return _float_8;
}

//ЕБАЛ
const Type& BuiltInTypesContainer::from_str(const std::string& str) const noexcept(false) {
	if(equals(str, Key::Boolean))
		return _boolean;
	if(equals(str, Key::Integer_1))
		return _integer_1;
	else if(equals(str, Key::Unsigned_integer_1))
		return _unsigned_integer_1;
	if(equals(str, Key::Integer_2))
		return _integer_2;
	else if(equals(str, Key::Unsigned_integer_2))
		return _unsigned_integer_2;
	if(equals(str, Key::Integer_4))
		return _integer_4;
	else if(equals(str, Key::Unsigned_integer_4))
		return _unsigned_integer_4;
	if(equals(str, Key::Integer_8))
		return _integer_8;
	else if(equals(str, Key::Unsigned_integer_8))
		return _unsigned_integer_8;
	if(equals(str, Key::Float_4))
		return _float_4;
	else if(equals(str, Key::Float_8))
		return _float_8;
	throw std::runtime_error("Undefined built-in type: " + str);
}

const PointerType& BuiltInTypesContainer::from_str_ptr(const std::string& str) const noexcept(false) {
	if(equals(str, Key::Boolean))
		return _boolean_ptr;
	if(equals(str, Key::Integer_1))
		return _integer_1_ptr;
	else if(equals(str, Key::Unsigned_integer_1))
		return _unsigned_integer_1_ptr;
	if(equals(str, Key::Integer_2))
		return _integer_2_ptr;
	else if(equals(str, Key::Unsigned_integer_2))
		return _unsigned_integer_2_ptr;
	if(equals(str, Key::Integer_4))
		return _integer_4_ptr;
	else if(equals(str, Key::Unsigned_integer_4))
		return _unsigned_integer_4_ptr;
	if(equals(str, Key::Integer_8))
		return _integer_8_ptr;
	else if(equals(str, Key::Unsigned_integer_8))
		return _unsigned_integer_8_ptr;
	if(equals(str, Key::Float_4))
		return _float_4_ptr;
	else if(equals(str, Key::Float_8))
		return _float_8_ptr;
	throw std::runtime_error("Undefined built-in type: " + str);
}


