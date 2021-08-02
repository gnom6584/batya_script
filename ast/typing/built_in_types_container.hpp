//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_
#define BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_

#include "type.hpp"
#include "common_type.hpp"
#include "pointer_type.hpp"

//////////////////////////////////////////////////////
//                  !ХУЙНЯ ПОЛНАЯ!                  //
//////////////////////////////////////////////////////


namespace batya_script::ast::typing {

class BuiltInTypesContainer {
public:

	[[nodiscard]] const Type& nothing() const noexcept(true);

	[[nodiscard]] const Type& boolean() const noexcept(true);

	[[nodiscard]] const Type& integer_1() const noexcept(true);

	[[nodiscard]] const Type& unsigned_integer_1() const noexcept(true);

	[[nodiscard]] const Type& integer_2() const noexcept(true);

	[[nodiscard]] const Type& unsigned_integer_2() const noexcept(true);

	[[nodiscard]] const Type& integer_4() const noexcept(true);

	[[nodiscard]] const Type& unsigned_integer_4() const noexcept(true);

	[[nodiscard]] const Type& integer_8() const noexcept(true);

	[[nodiscard]] const Type& unsigned_integer_8() const noexcept(true);

	[[nodiscard]] const Type& float_4() const noexcept(true);

	[[nodiscard]] const Type& float_8() const noexcept(true);

	[[nodiscard]] const Type& from_str(const std::string& str) const noexcept(false);

	[[nodiscard]] const PointerType& from_str_ptr(const std::string& str) const noexcept(false);

	[[nodiscard]] static const BuiltInTypesContainer& instance() noexcept(true);

private:
	BuiltInTypesContainer() noexcept(true);

	CommonType _boolean;

	CommonType _nothing;

	CommonType _integer_1;

	CommonType _unsigned_integer_1;

	CommonType _integer_2;

	CommonType _unsigned_integer_2;

	CommonType _integer_4;

	CommonType _unsigned_integer_4;

	CommonType _integer_8;

	CommonType _unsigned_integer_8;

	CommonType _float_4;

	CommonType _float_8;

	PointerType _boolean_ptr;

	PointerType _nothing_ptr;

	PointerType _integer_1_ptr;

	PointerType _unsigned_integer_1_ptr;

	PointerType _integer_2_ptr;

	PointerType _unsigned_integer_2_ptr;

	PointerType _integer_4_ptr;

	PointerType _unsigned_integer_4_ptr;

	PointerType _integer_8_ptr;

	PointerType _unsigned_integer_8_ptr;

	PointerType _float_4_ptr;

	PointerType _float_8_ptr;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_
