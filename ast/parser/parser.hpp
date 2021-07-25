//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_PARSER_PARSER_HPP_
#define BATYA_SCRIPT_AST_PARSER_PARSER_HPP_

#include "../../utility/single_pointer.hpp"
#include "../expression.hpp"

namespace batya_script::ast::parser {

[[nodiscard]] utility::SinglePointer<Expression> parse(const std::string& str) noexcept(false);

}

#endif //BATYA_SCRIPT_AST_PARSER_PARSER_HPP_
