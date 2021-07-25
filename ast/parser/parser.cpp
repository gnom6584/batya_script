//
// Created by Name on 24.07.2021.
//

#include <vector>
#include <iostream>
#include "parser.hpp"
#include "token.hpp"
#include "../expression_block.hpp"
#include "../typing/built_in_types_container.hpp"
#include "../../resources/keywords/keywords.hpp"
#include "../declarations/variable_declaration.hpp"


using namespace std;
using namespace batya_script;
using namespace ast;
using namespace declarations;
using namespace typing;
using namespace parser;
using namespace resources;
using namespace utility;

SinglePointer<Expression> parse_expression_block(const vector<Token>& tokens, size_t begin, size_t end) {
	auto e_blo_ptr = SinglePointer<Expression>::make<ExpressionBlock>(BuiltInTypesContainer::instance().nothing());
	auto& e_blo = reinterpret_cast<ExpressionBlock&>(*e_blo_ptr);
	for (int i = begin; i < end; ++i) {
		if(keywords::equals(tokens[i].string(), keywords::Key::Var)) {
			if(tokens.at(i + 1).string() == "=") {
				//e_blo.add(SinglePointer<Expression>::make<VariableDeclaration>(tokens[i + 1].string()));
			}
		}
	}
	return move(e_blo_ptr);
}


std::vector<Token> tokenize(const string& str) {
	std::vector<Token> tokens;

	size_t prev_break = 0;
	std::string token;

	for (size_t i = 0; i < str.length(); ++i) {
		if(isdigit(str[i]) || isalpha(str[i])) {
			token += str[i];
		}
		else {
			if(token.length() > 0) {
				tokens.emplace_back(Token(move(token), prev_break));
				token = string();
			}
			if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != 13) {
				tokens.emplace_back(Token(std::string(1, str[i]), i));
			}
			prev_break = i + 1;
		}
	}

	if(token.length() > 0)
		tokens.emplace_back(Token(move(token), prev_break));

	return tokens;
}


SinglePointer<Expression> parser::parse(const string& str) noexcept(false) {

	const auto tokens = tokenize(str);

	return move(parse_expression_block(tokens, 0, size(tokens)));
}
