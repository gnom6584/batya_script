//
// Created by Name on 01.08.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_POINTER_TYPE_HPP_
#define BATYA_SCRIPT_AST_TYPING_POINTER_TYPE_HPP_
#include "common_type.hpp"

namespace batya_script::ast::typing {

class PointerType : public Type {
public:
	explicit PointerType(const CommonType& type) noexcept(true);

	[[nodiscard]] size_t size() const noexcept(true) override;

	[[nodiscard]] std::string_view name() const noexcept(true) override;

private:
	const CommonType& _type;

	const std::string _name;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_POINTER_TYPE_HPP_
