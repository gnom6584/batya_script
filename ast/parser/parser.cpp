//
// Created by Name on 24.07.2021.
//

#include <vector>
#include <iostream>
#include <vector>
#include <map>
#include "parser.hpp"
#include "token.hpp"
#include "../expression_block.hpp"
#include "../typing/built_in_types_container.hpp"
#include "../../resources/keywords/keywords.hpp"
#include "../declarations/variable_declaration.hpp"
#include "../binary_operator.hpp"
#include "../literals/integer_literal.hpp"
#include "../literals/boolean_literal.hpp"
#include "../condition.hpp"
#include "../while.hpp"
#include "../declaration_reference.hpp"
#include "../assignment.hpp"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace declarations;
using namespace batya_script::ast::literals;
using namespace typing;
using namespace parser;
using namespace utility;
using namespace resources;

using Declarations = std::vector<std::map<std::string, const VariableDeclaration*>>;


const VariableDeclaration& find_declaration(const Declarations& decls, const std::string& str) {
	for (auto it = rbegin(decls); it != rend(decls); ++it) {
		auto f = it->find(str);
		if(f != end(*it))
			return *f->second;
	}
	throw runtime_error("Declaration with name (" + str + ") is not found!");
}


SinglePointer<Expression> parse_expression_block(const vector<Token>& tokens, size_t begin, size_t end, Declarations& decls);


SinglePointer<Expression> parse_expression(const vector<Token>& tokens, size_t begin, size_t& out_index, Declarations& decls) {
	std::optional<SinglePointer<Expression>> result_expression;

	if(keywords::equals(tokens[begin], keywords::Key::Var)) {
		auto with_assigment = tokens.at(begin + 2).string() == "=";
		auto with_assigment_and_explicit_type = tokens.at(begin + 4).string() == "=";
		if(with_assigment || with_assigment_and_explicit_type) {
			if(with_assigment_and_explicit_type) {
				const auto& expected_type = BuiltInTypesContainer::instance().from_str(tokens.at(begin + 3).string());
				auto assign_expression = parse_expression(tokens, begin + 5, out_index, decls);

				result_expression =
					SinglePointer<Expression>::make_derived<VariableDeclaration>(
					expected_type,
					tokens.at(begin + 1).string(),
					std::optional(move(assign_expression))
				);
				decls.back().emplace(tokens.at(begin + 1).string(), reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->()));
			}
			else {
				auto assign_expression = parse_expression(tokens, begin + 3, out_index, decls);
				result_expression =
					SinglePointer<Expression>::make_derived<VariableDeclaration>(
						assign_expression->result_type(),
						tokens.at(begin + 1).string(),
						move(assign_expression)
					);
				decls.back().emplace(tokens.at(begin + 1).string(), reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->()));
			}
		}
		else {
			if(tokens.at(begin + 2).string() == ":") {
				const auto& type = BuiltInTypesContainer::instance().from_str(tokens.at(begin + 3).string());
				result_expression = SinglePointer<Expression>::make_derived<VariableDeclaration>(
						type,
						tokens.at(begin + 1).string()
					);
				decls.back().emplace(tokens.at(begin + 1).string(), reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->()));
			}
			else
				throw runtime_error("Expected type specifier!");
		}
	}
	else if(keywords::equals(tokens[begin], keywords::Key::If)) {
		auto bool_expression = parse_expression(tokens, begin + 1, out_index, decls);
		auto on_true_expression = parse_expression(tokens, out_index, out_index, decls);
		if(keywords::equals(tokens[out_index], keywords::Key::Else)) {
			++out_index;
			result_expression = SinglePointer<Expression>::make_derived<Condition>(move(bool_expression), move(on_true_expression), parse_expression(tokens, out_index, out_index, decls));
		}
		else
			result_expression = SinglePointer<Expression>::make_derived<Condition>(move(bool_expression), move(on_true_expression));
	}
	else if(keywords::equals(tokens[begin], keywords::Key::While)) {
		auto bool_expression = parse_expression(tokens, begin + 1, out_index, decls);
		auto body = parse_expression(tokens, out_index, out_index, decls);
		result_expression = SinglePointer<Expression>::make_derived<While>(move(bool_expression), move(body));
	}
	else {
		const std::string& str = tokens[begin];

		if (str == "{") {
			size_t end = 0;
			int depth = 0;
			for (int i = begin; i < std::size(tokens); ++i) {
				if(tokens.at(i).string() == "{")
					++depth;
				else if(tokens.at(i).string() == "}") {
					--depth;
					if(depth == 0) {
						out_index = i + 1;
						break;
					}
				}
			}
			result_expression = parse_expression_block(tokens, begin + 1, out_index - 1, decls);
		}
		else {
			if (keywords::equals(str, keywords::Key::True) || keywords::equals(str, keywords::Key::False)) {
				result_expression = SinglePointer<Expression>::make_derived<BooleanLiteral>(keywords::equals(str, keywords::Key::True));
				out_index = begin + 1;
			} else {
				if (std::isalpha(str[0])) {
					if(tokens.at(begin + 1).string() == "=") {
						result_expression = SinglePointer<Expression>::make_derived<Assignment>(find_declaration(decls, str), parse_expression(tokens, begin + 2, out_index, decls));
					}
					else {
						result_expression = SinglePointer<Expression>::make_derived<DeclarationReference>(find_declaration(decls, str));
						out_index = begin + 1;
					}
				} else {
					auto is_integer = all_of(std::begin(str), end(str), [](char character) {
						return std::isdigit(character);
					});
					if (is_integer) {
						result_expression = SinglePointer<Expression>::make_derived<IntegerLiteral>(stoi(str));
						out_index = begin + 1;
					} else {
						throw runtime_error("Undefined key word: " + str);
					}
				}
			}
		}
	}

	//const static auto binary_operators = {
	//	"+", "-", "*", "/", "%", "<", ">"
	//};

	//if(out_index < std::size(tokens))
	//	while(count(std::begin(binary_operators), end(binary_operators), tokens[out_index].string()))
	//		result_expression = SinglePointer<Expression>::make_derived<BinaryOperator>(result_expression.value()->result_type(), tokens[out_index], move(result_expression.value()), parse_expression(tokens, out_index + 1, out_index, decls));

	return move(result_expression.value());
}

SinglePointer<Expression> parse_expression_block(const vector<Token>& tokens, size_t begin, size_t end, Declarations& decls) {
	auto expressions = std::vector<SinglePointer<Expression>>();
	decls.emplace_back();
	size_t i = begin;
	while(i < end) {
		std::cout << i << std::endl;
		expressions.emplace_back(parse_expression(tokens, i, i, decls));
	}
	decls.pop_back();
	return SinglePointer<Expression>::make_derived<ExpressionBlock>(expressions.back()->result_type(), move(expressions));
}


std::vector<Token> tokenize(const string& str) {
	std::vector<Token> tokens;

	size_t prev_break = 0;
	std::string token;

	for (size_t i = 0; i < str.length(); ++i)
		if(isdigit(str[i]) || isalpha(str[i]))
			token += str[i];
		else {
			if(token.length() > 0) {
				tokens.emplace_back(Token(move(token), prev_break));
				token = string();
			}
			if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != 13)
				tokens.emplace_back(Token(std::string(1, str[i]), i));

			prev_break = i + 1;
		}

	if(token.length() > 0)
		tokens.emplace_back(Token(move(token), prev_break));

	return tokens;
}


SinglePointer<Expression> parser::parse(const string& str) noexcept(false) {

	const auto tokens = tokenize(str);
	Declarations var_decls;
	return move(parse_expression_block(tokens, 0, size(tokens), var_decls));
}
