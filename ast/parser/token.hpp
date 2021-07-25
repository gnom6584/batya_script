//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_PARSER_TOKEN_HPP_
#define BATYA_SCRIPT_AST_PARSER_TOKEN_HPP_

#include <string>

namespace batya_script::ast::parser {

class Token {
public:
	Token(std::string string, size_t position) noexcept(true);

	[[nodiscard]] const std::string& string() const noexcept(true);

	[[nodiscard]] size_t position() const noexcept(true);

private:
	std::string _string;
	size_t _position;
};

}

#endif //BATYA_SCRIPT_AST_PARSER_TOKEN_HPP_
