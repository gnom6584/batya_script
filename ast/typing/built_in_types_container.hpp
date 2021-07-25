//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_
#define BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_

#include "type.hpp"
#include "common_type.hpp"

namespace batya_script::ast::typing {

class BuiltInTypesContainer {
public:

	[[nodiscard]] const Type& nothing() const;

	[[nodiscard]] const Type& boolean() const;

	[[nodiscard]] const Type& integer() const;

	[[nodiscard]] static const BuiltInTypesContainer& instance() noexcept(true);

private:
	BuiltInTypesContainer() noexcept(true);

	CommonType _boolean;

	CommonType _nothing;

	CommonType _integer;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_BUILT_IN_TYPES_CONTAINER_HPP_
