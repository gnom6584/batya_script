//
// Created by Name on 23.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPE_HPP_
#define BATYA_SCRIPT_AST_TYPE_HPP_

#include <string>

namespace batya_script::ast::typing
{

class Type {
public:
	[[nodiscard]] virtual std::string_view name() const noexcept(true) = 0;

	[[nodiscard]] bool operator==(const Type& right) const noexcept(true);

	[[nodiscard]] bool operator!=(const Type& right) const noexcept(true);
};

}

#endif //BATYA_SCRIPT_AST_TYPE_HPP_
