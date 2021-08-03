//
// Created by Name on 24.07.2021.
//

#include "built_in_types_container.hpp"
#include "../../resources/keywords/keys.hpp"
#include "../../resources/keywords/keywords.hpp"

using namespace batya_script::ast::typing;
using namespace batya_script::resources::keywords;

BuiltInTypesContainer::BuiltInTypesContainer() noexcept(true) :
	_nothing(CommonType("Nothing", 0)),
	_boolean(CommonType("Bool", sizeof(bool))),
	_integer_1(CommonType("I1", sizeof(char))),
	_unsigned_integer_1(CommonType("UI", sizeof(unsigned char))),
	_integer_2(CommonType("I2", sizeof(short))),
	_unsigned_integer_2(CommonType("U2", sizeof(unsigned short))),
	_integer_4(CommonType("I4", sizeof(int))),
	_unsigned_integer_4(CommonType("U4", sizeof(unsigned int))),
	_integer_8(CommonType("I8", sizeof(int64_t))),
	_unsigned_integer_8(CommonType("U8", sizeof(uint64_t))),
	_float_4(CommonType("F4", sizeof(float))),
	_float_8(CommonType("F8", sizeof(double ))),
	_ptr(CommonType("Ptr", sizeof(uintptr_t))),
	_u_size(CommonType("USize", sizeof(size_t)))
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

const Type& BuiltInTypesContainer::ptr() const noexcept(true) {
	return _ptr;
}


const Type& BuiltInTypesContainer::u_size() const noexcept(true) {
	return _u_size;
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
	else if(equals(str, Key::Ptr))
		return _ptr;
	else if(equals(str, Key::Usize))
		return _u_size;
	throw std::runtime_error("Undefined built-in type: " + str);
}

