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
#include "../unary_operator.hpp"
#include "../literals/integer_literal.hpp"
#include "../literals/boolean_literal.hpp"
#include "../condition.hpp"
#include "../while.hpp"
#include "../declaration_reference.hpp"
#include "../assignment.hpp"
#include "../declarations/function_declaration.hpp"
#include "../function_invocation.hpp"
#include <functional>

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace declarations;
using namespace batya_script::ast::literals;
using namespace typing;
using namespace parser;
using namespace utility;
using namespace resources;

struct Declarations {
	std::vector<std::map<std::string, const VariableDeclaration*>> variables;

	std::vector<std::map<std::string, const FunctionDeclaration*>> functions;

	const VariableDeclaration& find_variable(const std::string& str) {
		for (auto it = rbegin(variables); it != rend(variables); ++it) {
			auto f = it->find(str);
			if(f != end(*it))
				return *f->second;
		}
		throw runtime_error("Declaration with name (" + str + ") is not found!");
	}

	const FunctionDeclaration& find_function(const std::string& str) {
		for (auto it = rbegin(functions); it != rend(functions); ++it) {
			auto f = it->find(str);
			if(f != end(*it))
				return *f->second;
		}
		throw runtime_error("Function with name (" + str + ") is not found!");
	}
};




SinglePointer<Expression> parse_expression_block(const vector<Token>& tokens, size_t begin, size_t end, Declarations& decls);


SinglePointer<Expression> parse_expression(const vector<Token>& tokens, size_t begin, size_t& out_index, Declarations& decls, bool check_operators = true) {
	std::optional<SinglePointer<Expression>> result_expression;

	if(keywords::equals(tokens[begin], keywords::Key::Var)) {
		auto with_assigment = begin + 2 < size(tokens) ? tokens.at(begin + 2).string() == "=" : false;
		auto with_assigment_and_explicit_type =  begin + 4 < size(tokens) ? tokens.at(begin + 4).string() == "=" : false;
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
				decls.variables.back()[tokens.at(begin + 1).string()] = reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->());
			}
			else {
				auto assign_expression = parse_expression(tokens, begin + 3, out_index, decls);
				result_expression =
					SinglePointer<Expression>::make_derived<VariableDeclaration>(
						assign_expression->result_type(),
						tokens.at(begin + 1).string(),
						move(assign_expression)
					);
				decls.variables.back()[tokens.at(begin + 1)] = reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->());
			}
		}
		else {
			if(tokens.at(begin + 2).string() == ":") {
				const auto& type = BuiltInTypesContainer::instance().from_str(tokens.at(begin + 3).string());
				result_expression = SinglePointer<Expression>::make_derived<VariableDeclaration>(
						type,
						tokens.at(begin + 1).string()
					);
				decls.variables.back()[tokens.at(begin + 1).string()] = reinterpret_cast<const VariableDeclaration*>(result_expression.value().operator->());
			}
			else
				throw runtime_error("Expected type specifier!");
		}
	}
	else if(keywords::equals(tokens[begin], keywords::Key::If)) {
		decls.variables.emplace_back();
		decls.functions.emplace_back();
		auto bool_expression = parse_expression(tokens, begin + 1, out_index, decls);
		auto on_true_expression = parse_expression(tokens, out_index, out_index, decls);
		if(keywords::equals(tokens[out_index], keywords::Key::Else)) {
			++out_index;
			result_expression = SinglePointer<Expression>::make_derived<Condition>(move(bool_expression), move(on_true_expression), parse_expression(tokens, out_index, out_index, decls));
		}
		else
			result_expression = SinglePointer<Expression>::make_derived<Condition>(move(bool_expression), move(on_true_expression));
		decls.variables.pop_back();
		decls.functions.pop_back();
	}
	else if(keywords::equals(tokens[begin], keywords::Key::While)) {
		decls.variables.emplace_back();
		decls.functions.emplace_back();
		auto bool_expression = parse_expression(tokens, begin + 1, out_index, decls);
		auto body = parse_expression(tokens, out_index, out_index, decls);
		result_expression = SinglePointer<Expression>::make_derived<While>(move(bool_expression), move(body));
		decls.variables.pop_back();
		decls.functions.pop_back();
	}
	else if(keywords::equals(tokens[begin], keywords::Key::Fun)) {
		auto f_name = tokens.at(begin + 1).string();
		if(tokens.at(begin + 2).string() != "(")
			throw runtime_error("Invalid function declaration");

		const Type* return_type;
		vector<pair<string, reference_wrapper<const typing::Type>>> params;

		auto j = begin + 2;
		if(tokens.at(begin + 3).string() == ")") {
			if(tokens.at(j + 2).string() == ":")
				return_type = &BuiltInTypesContainer::instance().from_str(tokens.at(j + 3));
			j += 4;
		}
		else {
			do {
				++j;
				params.emplace_back(tokens.at(j), BuiltInTypesContainer::instance().from_str(tokens.at(j + 1)));
				j += 2;
			}
			while(tokens.at(j).string() == ",");
			if(tokens.at(j + 1).string() == ":")
				return_type = &BuiltInTypesContainer::instance().from_str(tokens.at(j + 2));
			j += 3;
		}

		Declarations f_decls;
		f_decls.functions = decls.functions;
		f_decls.functions.back().emplace(f_name, new FunctionDeclaration(f_name, params, *return_type));
		f_decls.variables.emplace_back();

		for(const auto& param : params) {
			f_decls.variables.back().emplace(param.first, new VariableDeclaration(param.second, param.first));
		}
		result_expression = SinglePointer<Expression>::make_derived<FunctionDeclaration>(move(f_name), move(params), *return_type,
			parse_expression(tokens, j, out_index, f_decls));

		const auto& casted = (const FunctionDeclaration&)**result_expression;

		decls.functions.back().emplace(casted.name(), &casted);
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
			}
			else {
				if (std::isalpha(str[0])) {
					if(begin + 1 < tokens.size()) {
						if (tokens.at(begin + 1).string() == "=")
							result_expression = SinglePointer<Expression>::make_derived<Assignment>(decls.find_variable(str), parse_expression(tokens, begin + 2, out_index, decls));
						else if (tokens.at(begin + 1).string() == "(") {
							const auto& fd = decls.find_function(str);
							vector<SinglePointer<Expression>> args;

							if (tokens.at(begin + 2).string() != ")") {
								args.emplace_back(parse_expression(tokens, begin + 2, out_index, decls));
								while (tokens.at(out_index).string() == ",")
									args.emplace_back(parse_expression(tokens, out_index + 1, out_index, decls));
								out_index++;
							} else
								out_index += 2;

							result_expression = SinglePointer<Expression>::make_derived<FunctionInvocation>(fd, move(args));
						}
						else {
							result_expression = SinglePointer<Expression>::make_derived<DeclarationReference>(decls.find_variable(str));
							out_index = begin + 1;
						}
					}
					else {
						result_expression = SinglePointer<Expression>::make_derived<DeclarationReference>(decls.find_variable(str));
						out_index = begin + 1;
					}
				}
				else {
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


//	if(out_index < std::size(tokens))
//		while(count(std::begin(binary_operators), end(binary_operators), tokens[out_index].string()))
//			result_expression = SinglePointer<Expression>::make_derived<BinaryOperator>(result_expression.value()->result_type(), tokens[out_index], move(result_expression.value()), parse_expression(tokens, out_index + 1, out_index, decls));

//	if(out_index < std::size(tokens))
//		while(count(std::begin(binary_operators), end(binary_operators), tokens[out_index].string()))


	return move(result_expression.value());
}

SinglePointer<Expression> parse_expression_block(const vector<Token>& tokens, size_t begin, size_t end, Declarations& decls) {
	auto expressions = std::vector<SinglePointer<Expression>>();
	decls.variables.emplace_back();
	decls.functions.emplace_back();
	size_t i = begin;
	while(i < end) {
		//std::cout << i << std::endl;
		expressions.emplace_back(parse_expression(tokens, i, i, decls));
	}
	decls.functions.pop_back();
	decls.variables.pop_back();
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

#include <functional>

SinglePointer<Expression> parser::parse(const string& str) noexcept(false) {
	const auto tokens = tokenize(str);
	Declarations var_decls;
	var_decls.functions.emplace_back();
	var_decls.functions.back().emplace("greater", new FunctionDeclaration("greater",
		{{"first", BuiltInTypesContainer::instance().integer_4()}, {"second", BuiltInTypesContainer::instance().integer_4()}},
		BuiltInTypesContainer::instance().boolean(), SinglePointer<Expression>::make_derived<BooleanLiteral>(false)));
	var_decls.functions.back().emplace("less", new FunctionDeclaration("less",
																		  {{"first", BuiltInTypesContainer::instance().integer_4()}, {"second", BuiltInTypesContainer::instance().integer_4()}},
																		  BuiltInTypesContainer::instance().boolean(), SinglePointer<Expression>::make_derived<BooleanLiteral>(false)));
	var_decls.functions.back().emplace("not", new FunctionDeclaration("not",
																		  {{"first", BuiltInTypesContainer::instance().boolean()}},
																		  BuiltInTypesContainer::instance().boolean(), SinglePointer<Expression>::make_derived<BooleanLiteral>(false)));
	var_decls.functions.back().emplace("subtract", new FunctionDeclaration("subtract",
																		  {{"first", BuiltInTypesContainer::instance().integer_4()}, {"second", BuiltInTypesContainer::instance().integer_4()}},
																		  BuiltInTypesContainer::instance().integer_4(), SinglePointer<Expression>::make_derived<IntegerLiteral>(0)));

	var_decls.functions.back().emplace("add", new FunctionDeclaration("add",
																		   {{"first", BuiltInTypesContainer::instance().integer_4()}, {"second", BuiltInTypesContainer::instance().integer_4()}},
																		   BuiltInTypesContainer::instance().integer_4(), SinglePointer<Expression>::make_derived<IntegerLiteral>(0)));

	var_decls.functions.back().emplace("multiply", new FunctionDeclaration("multiply",
																		   {{"first", BuiltInTypesContainer::instance().integer_4()}, {"second", BuiltInTypesContainer::instance().integer_4()}},
																		   BuiltInTypesContainer::instance().integer_4(), SinglePointer<Expression>::make_derived<IntegerLiteral>(0)));

	var_decls.functions.back().emplace("a", new FunctionDeclaration("a",
																		   {{"first", BuiltInTypesContainer::instance().integer_4()}},
																		   BuiltInTypesContainer::instance().integer_4(), SinglePointer<Expression>::make_derived<IntegerLiteral>(0)));

	return move(parse_expression_block(tokens, 0, size(tokens), var_decls));
}
