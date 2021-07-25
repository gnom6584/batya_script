//
// Created by Name on 24.07.2021.
//

#include "token.hpp"

using namespace std;
using namespace batya_script::ast::parser;


Token::Token(std::string string, size_t position) noexcept(true)
	: _string(move(string)), _position(position) {

}


const string& Token::string() const noexcept(true) {
	return _string;
}


size_t Token::position() const noexcept(true) {
	return _position;
}
