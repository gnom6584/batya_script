//
// Created by Name on 28.07.2021.
//

#include "compiler.hpp"

#include <map>
#include <utility>
#include <iostream>

#include "../bytecode/codes.hpp"
#include "../ast/assignment.hpp"
#include "../ast/binary_operator.hpp"
#include "../ast/condition.hpp"
#include "../ast/declarations/declaration.hpp"
#include "../ast/declarations/function_declaration.hpp"
#include "../ast/declarations/variable_declaration.hpp"
#include "../ast/declaration_reference.hpp"
#include "../ast/expression.hpp"
#include "../ast/expression_block.hpp"
#include "../ast/function_invocation.hpp"
#include "../ast/literals/boolean_literal.hpp"
#include "../ast/literals/integer_literal.hpp"
#include "../ast/literals/literal.hpp"
#include "../ast/parser/parser.hpp"
#include "../ast/parser/token.hpp"
#include "../ast/typing/binary_operator.hpp"
#include "../ast/typing/built_in_types_container.hpp"
#include "../ast/typing/common_type.hpp"
#include "../ast/typing/type.hpp"
#include "../ast/typing/unary_operator.hpp"
#include "../ast/unary_operator.hpp"
#include "../ast/while.hpp"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace utility;
using namespace declarations;
using namespace typing;
using namespace bytecode;
using namespace ast::literals;

struct Declarations {
	Declarations() = default;

	Declarations(const Declarations&) = delete;

	Declarations& operator=(Declarations&) = delete;

	vector<map<string, size_t>> var_s;

	vector<map<string, pair<const FunctionDeclaration*, size_t>>> fun_s;

	vector<size_t> sp;

	size_t find_variable(const std::string& str) {
		for (auto it = rbegin(var_s); it != rend(var_s); ++it) {
			auto f = it->find(str);
			if (f != end(*it))
				return f->second;
		}
		throw runtime_error("Declaration with name (" + str + ") is not found!");
	}

	const FunctionDeclaration& find_function(const std::string& str) {
		for (auto it = rbegin(fun_s); it != rend(fun_s); ++it) {
			auto f = it->find(str);
			if (f != end(*it))
				return *f->second.first;
		}
		throw runtime_error("Function with name (" + str + ") is not found!");
	}
};

void compile_expression(BytecodeBuilder& builder, const Expression& expr, Declarations& declarations, optional<size_t> out_result);


void compile_integer_literal(BytecodeBuilder& builder, const IntegerLiteral& liter, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_integer_32(out_result.value(), liter.value());
	}
}


void compile_boolean_literal(BytecodeBuilder& builder, const BooleanLiteral& liter, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_boolean(out_result.value(), liter.value());
	}
}

void compile_condition(BytecodeBuilder& builder, const Condition& cond, Declarations& declarations, optional<size_t> out_result) {
	builder.stack_allocate(cond.bool_expression().result_type().size());
	auto temp = declarations.sp.back();

	declarations.sp.back() += cond.bool_expression().result_type().size();

	compile_expression(builder, cond.bool_expression(), declarations, temp);

	auto go_to_pos = builder.position();

	BytecodeBuilder expr_builder;
	compile_expression(expr_builder, cond.on_true_expression(), declarations, {});
	auto expr_bc = expr_builder.build();
	builder.go_to_if(temp, builder.position() + expr_bc.size() + 1 + 16);
	builder.append(expr_bc);


	auto label = builder.position();

	auto size = label - go_to_pos;

}

void compile_var_declaration(BytecodeBuilder& builder, const VariableDeclaration& vd, Declarations& declarations, optional<size_t> out_result) {
	builder.stack_allocate(vd.result_type().size());
	auto temp = declarations.sp.back();
	declarations.var_s.back()[vd.name()] = temp;

	declarations.sp.back() += vd.result_type().size();

	if (vd.has_assignment()) {
		compile_expression(builder, vd.assignment(), declarations, temp);
	}

	if (out_result.has_value()) {
		builder.copy(out_result.value(), temp, vd.result_type().size());
	}
}

void compile_assigment(BytecodeBuilder& builder, const Assignment& assignment, Declarations& declarations, optional<size_t> out_result) {
	auto temp = declarations.sp.back();
	compile_expression(builder, assignment.assignment_expression(), declarations, temp);

	size_t sum = 0;
	for (int i = 0; i < declarations.sp.size(); ++i) {
		sum += declarations.sp[i];
	}
	builder.copy(sum + declarations.find_variable(assignment.declaration().name()), declarations.sp.back(), assignment.result_type().size());

	if (out_result.has_value())
		builder.copy(out_result.value(), temp, assignment.result_type().size());
}

void compile_decl_reference(BytecodeBuilder& builder, const DeclarationReference& ref, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value())
		builder.copy(out_result.value(), declarations.find_variable(ref.variable_declaration().name()), ref.variable_declaration().result_type().size());
}


void compile_block(BytecodeBuilder& builder, const ExpressionBlock& block, Declarations& declarations, optional<size_t> out_result) {
	auto temp = declarations.sp.back();
	builder.stack_push();
	declarations.var_s.emplace_back();
	declarations.fun_s.emplace_back();
	declarations.sp.emplace_back(0);
	builder.stack_allocate(block.result_type().size());
	declarations.sp.back() += block.result_type().size();
	for (auto i = block.min_index(); i < block.max_index(); ++i)
		compile_expression(builder, block[i], declarations, {});
	compile_expression(builder, block[block.max_index()], declarations, 0);
	declarations.sp.pop_back();
	declarations.var_s.pop_back();
	declarations.fun_s.pop_back();
	builder.stack_pop();

	if (out_result.has_value())
		builder.copy(out_result.value(), temp, block.result_type().size());
}


void compile_expression(BytecodeBuilder& builder,const Expression& expr, Declarations& declarations, optional<size_t> out_result) {

	if (typeid(expr) == typeid(const ExpressionBlock&)) {
		compile_block(builder, (const ExpressionBlock&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const IntegerLiteral&)) {
		compile_integer_literal(builder, (const IntegerLiteral&)expr, declarations, out_result);
	}
	else if (typeid(expr) == typeid(const BooleanLiteral&)) {

		compile_boolean_literal(builder, (const BooleanLiteral&)expr, declarations, out_result);
	}
	else if (typeid(expr) == typeid(const Assignment&)) {

		compile_assigment(builder, (const Assignment&)expr, declarations, out_result);
	}
	else if (typeid(expr) == typeid(const VariableDeclaration&)) {

		compile_var_declaration(builder, (const VariableDeclaration&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const DeclarationReference&)) {

		compile_decl_reference(builder, (const DeclarationReference&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const Condition&)) {

		compile_condition(builder, (const Condition&)expr, declarations, out_result);
	}
	else
		throw runtime_error("Not implemented");
}


Bytecode Compiler::compile(const string& str) {
	auto ast = parser::parse(str);
	Declarations decls;
	decls.var_s.emplace_back();
	decls.fun_s.emplace_back();
	decls.sp = {0};
	decls.sp.back() += ast->result_type().size();
	size_t result = 0;
	BytecodeBuilder builder;
	builder.stack_allocate(ast->result_type().size());
	compile_expression(builder, *ast, decls, result);
	return builder.build();
}
