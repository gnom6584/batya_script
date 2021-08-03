//
// Created by Name on 02.08.2021.
//

#ifndef BATYA_SCRIPT_AST_LITERALS_USIZE_LITERAL_HPP_
#define BATYA_SCRIPT_AST_LITERALS_USIZE_LITERAL_HPP_

#include <vector>
#include "literal.hpp"

namespace batya_script::ast::literals {

class USizeLiteral : public Literal {
public:
	explicit USizeLiteral(size_t value) noexcept(true);

	[[nodiscard]] size_t value() const noexcept(true);

private:
	size_t _value;

};
}

#endif //BATYA_SCRIPT_AST_LITERALS_USIZE_LITERAL_HPP_
