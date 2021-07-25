//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
#define BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_

#include "type.hpp"

namespace batya_script::ast::typing {

class CommonType : public Type {
public:

	explicit CommonType(std::string name) noexcept(true);

	[[nodiscard]] std::string_view name() const noexcept(true) override;

private:

	const std::string _name;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
