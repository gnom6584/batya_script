//
// Created by Name on 28.07.2021.
//

#include "compiler.hpp"

#include <map>
#include <utility>
#include <iostream>
#include <functional>

#include "../bytecode/codes.hpp"
#include "../ast/assignment.hpp"
#include "../ast/condition.hpp"
#include "../ast/declarations/declaration.hpp"
#include "../ast/declarations/function_declaration.hpp"
#include "../ast/declarations/variable_declaration.hpp"
#include "../ast/declarations/struct_declaration.hpp"
#include "../ast/declaration_reference.hpp"
#include "../ast/expression.hpp"
#include "../ast/expression_block.hpp"
#include "../ast/function_invocation.hpp"
#include "../ast/literals/boolean_literal.hpp"
#include "../ast/literals/integer_literal.hpp"
#include "../ast/literals/literal.hpp"
#include "../ast/parser/parser.hpp"
#include "../ast/parser/token.hpp"
#include "../ast/typing/built_in_types_container.hpp"
#include "../ast/typing/common_type.hpp"
#include "../ast/typing/type.hpp"
#include "../ast/while.hpp"
#include "../ast/address.hpp"
#include "../ast/literals/long_literal.hpp"
#include "../ast/literals/usize_literal.hpp"

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

	vector<map<string, size_t>> fun_s;

	size_t sp {};

	size_t find_variable(const std::string& str) {
		for (auto it = rbegin(var_s); it != rend(var_s); ++it) {
			auto f = it->find(str);
			if (f != end(*it))
				return f->second;
		}
		throw runtime_error("Declaration with name (" + str + ") is not found!");
	}

	size_t find_function(const std::string& str) {
		for (auto it = rbegin(fun_s); it != rend(fun_s); ++it) {
			auto f = it->find(str);
			if (f != end(*it))
				return f->second;
		}
		throw runtime_error("Function with name (" + str + ") is not found!");
	}
};

size_t find_decl(Declarations& decls, const DeclarationReference& dref) {
	return decls.find_variable(dref.members()[0]) + dref.offset();
}

void compile_expression(BytecodeBuilder& builder, const Expression& expr, Declarations& declarations, optional<size_t> out_result);

void compile_function_declaration(const FunctionDeclaration& expr, Declarations& declarations, optional<size_t> out_result) {
	BytecodeBuilder builder;
	auto decls = Declarations();
	auto* bytecode_ptr = new Bytecode();
	decls.fun_s = declarations.fun_s;
	decls.fun_s.back().emplace(expr.get_signature(), (size_t)bytecode_ptr);
	const auto& pms = expr.parameters();
	decls.var_s.emplace_back();

	size_t sp = 0;
	for(const auto & pm : pms) {

		decls.var_s.back().emplace(pm.first, sp);
		sp += pm.second.get().size();
	}
	decls.sp = sp;


	compile_expression(builder, expr.body(), decls, 0);
	*bytecode_ptr = builder.build();
	declarations.fun_s.back().emplace(expr.get_signature(), (size_t)bytecode_ptr);
}

void compile_integer_literal(BytecodeBuilder& builder, const IntegerLiteral& liter, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_integer_32(out_result.value(), liter.value());
	}
}

void compile_u8_literal(BytecodeBuilder& builder, const UnsignedInteger8Literal& literal, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_unsigned_integer_64(out_result.value(), literal.value());
	}
}

void compile_u_size_literal(BytecodeBuilder& builder, const USizeLiteral& literal, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_unsigned_integer_64(out_result.value(), literal.value());
	}
}


void compile_boolean_literal(BytecodeBuilder& builder, const BooleanLiteral& liter, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value()) {
		builder.set_boolean(out_result.value(), liter.value());
	}
}

void normalize_goto_s(Bytecode& bc, size_t start_position) {
	for (int i = 0; i < bc.size();) {
		if (*(bc.data() + i) == codes::go_to_if)
			*(size_t*)(bc.data() + i + 1 + 8) += start_position;
		else if (*(bc.data() + i) == codes::go_to)
			*(size_t*)(bc.data() + i + 1) += start_position;
		i += 1 + codes::size_of[*(bc.data() + i)];
	}
}

void compile_condition(BytecodeBuilder& builder, const Condition& cond, Declarations& declarations, optional<size_t> out_result) {
	builder.stack_allocate(cond.bool_expression().result_type().size());
	auto temp = declarations.sp;

	declarations.sp += cond.bool_expression().result_type().size();

	compile_expression(builder, cond.bool_expression(), declarations, temp);


	builder.inverse_boolean(temp);

	if (!cond.has_on_false_expression()) {
		BytecodeBuilder expr_builder;
		compile_expression(expr_builder, cond.on_true_expression(), declarations, {});
		auto expr_bc = expr_builder.build();
		builder.go_to_if(temp, builder.position() + expr_bc.size() + 1 + codes::size_of[codes::go_to_if]);
		normalize_goto_s(expr_bc, builder.position());
		builder.append(expr_bc);
	} else {
		BytecodeBuilder expr_builder;
		compile_expression(expr_builder, cond.on_true_expression(), declarations, out_result);
		auto expr_bc = expr_builder.build();
		builder.go_to_if(temp, builder.position() + expr_bc.size() + 1 + codes::size_of[codes::go_to_if] + 1 + codes::size_of[codes::go_to]);
		normalize_goto_s(expr_bc, builder.position());
		builder.append(expr_bc);
		BytecodeBuilder expr_builder_else;
		compile_expression(expr_builder_else, cond.on_false_expression(), declarations, out_result);
		auto else_bc = expr_builder_else.build();
		builder.go_to(builder.position() + else_bc.size() + 1 + codes::size_of[codes::go_to]);
		normalize_goto_s(else_bc, builder.position());
		builder.append(else_bc);
	}

}


void compile_while(BytecodeBuilder& builder, const While& vd, Declarations& declarations, optional<size_t> out_result) {
	builder.stack_allocate(vd.condition().result_type().size());
	auto temp = declarations.sp;
	auto label = builder.position();
	declarations.sp += vd.condition().result_type().size();
	compile_expression(builder, vd.condition(), declarations, temp);
	builder.inverse_boolean(temp);
	BytecodeBuilder body_builder;
	compile_expression(body_builder, vd.body(), declarations, {});
	auto body_bc = body_builder.build();
	builder.go_to_if(temp, builder.position() + body_bc.size() + 1 + codes::size_of[codes::go_to_if] + 1 + codes::size_of[codes::go_to]);
	normalize_goto_s(body_bc, builder.position());
	builder.append(body_bc);
	builder.go_to(label);
}


void compile_var_declaration(BytecodeBuilder& builder, const VariableDeclaration& vd, Declarations& declarations, optional<size_t> out_result) {
	builder.stack_allocate(vd.result_type().size());
	auto temp = declarations.sp;
	declarations.var_s.back()[vd.name()] = temp;

	declarations.sp += vd.result_type().size();

	if (vd.has_assignment()) {
		compile_expression(builder, vd.assignment(), declarations, temp);
	}

	if (out_result.has_value()) {
		builder.copy(out_result.value(), temp, vd.result_type().size());
	}
}


void compile_assigment(BytecodeBuilder& builder, const Assignment& assignment, Declarations& declarations, optional<size_t> out_result) {
	auto temp = declarations.sp;
	compile_expression(builder, assignment.assignment_expression(), declarations, temp);

	builder.copy(find_decl(declarations, assignment.declaration()), temp, assignment.result_type().size());

	if (out_result.has_value())
		builder.copy(out_result.value(), temp, assignment.result_type().size());
}


void compile_decl_reference(BytecodeBuilder& builder, const DeclarationReference& ref, Declarations& declarations, optional<size_t> out_result) {
	if (out_result.has_value())
		builder.copy(out_result.value(), find_decl(declarations, ref), ref.result_type().size());
}


void compile_function_invocation(BytecodeBuilder& builder, const FunctionInvocation& fi, Declarations& declarations, optional<size_t> out_result) {
	const auto& return_type = fi.result_type();
	const auto return_type_size = return_type.size();
	const auto& args = fi.arguments();

	auto temp = declarations.sp;
	auto ptr = temp;
	for(auto& arg : args) {
		builder.stack_allocate(arg->result_type().size());
		declarations.sp += arg->result_type().size();
		compile_expression(builder, *arg, declarations, ptr);
		ptr += arg->result_type().size();
	}
	builder.stack_free(declarations.sp - temp);
	builder.stack_push();
	builder.stack_allocate(declarations.sp - temp);
	builder.execute_byte_code(declarations.find_function(fi.declaration().get_signature()));
	builder.stack_pop();
	declarations.sp = temp;
	if (out_result.has_value())
		builder.copy(out_result.value(), temp, return_type_size);
}

void compile_address(BytecodeBuilder& builder, const Address& address, Declarations& declarations, optional<size_t> out_result) {
	compile_expression(builder, address.declaration_reference(), declarations, {});
	if(out_result.has_value())
		builder.address_from_stack(declarations.find_variable(address.declaration_reference().members()[0]), out_result.value());
}

void compile_block(BytecodeBuilder& builder, const ExpressionBlock& block, Declarations& declarations, optional<size_t> out_result) {
	auto temp = declarations.sp;
	//builder.stack_push();
	declarations.var_s.emplace_back();
	declarations.fun_s.emplace_back();
	builder.stack_allocate(block.result_type().size());
	declarations.sp += block.result_type().size();

	for (auto i = block.min_index(); i < block.max_index(); ++i)
		compile_expression(builder, block[i], declarations, {});

	compile_expression(builder, block[block.max_index()], declarations, temp);

	declarations.var_s.pop_back();
	declarations.fun_s.pop_back();
	//builder.stack_pop();

	if (out_result.has_value())
		builder.copy(out_result.value(), temp, block.result_type().size());

	builder.stack_free(declarations.sp - temp);
	declarations.sp = temp;
}


void compile_expression(BytecodeBuilder& builder, const Expression& expr, Declarations& declarations, optional<size_t> out_result) {
	std::cout << typeid(expr).name() << std::endl;
	if (typeid(expr) == typeid(const ExpressionBlock&)) {
		compile_block(builder, (const ExpressionBlock&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const IntegerLiteral&)) {
		compile_integer_literal(builder, (const IntegerLiteral&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const UnsignedInteger8Literal&)) {
		compile_u8_literal(builder, (const UnsignedInteger8Literal&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const USizeLiteral&)) {
		compile_u_size_literal(builder, (const USizeLiteral&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const BooleanLiteral&)) {
		compile_boolean_literal(builder, (const BooleanLiteral&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const Assignment&)) {
		compile_assigment(builder, (const Assignment&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const VariableDeclaration&)) {
		compile_var_declaration(builder, (const VariableDeclaration&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const DeclarationReference&)) {
		compile_decl_reference(builder, (const DeclarationReference&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const Condition&)) {
		compile_condition(builder, (const Condition&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const FunctionInvocation&)) {
		compile_function_invocation(builder, (const FunctionInvocation&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const While&)) {
		compile_while(builder, (const While&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const FunctionDeclaration&)) {
		compile_function_declaration((const FunctionDeclaration&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const Address&)) {
		compile_address(builder, (const Address&)expr, declarations, out_result);
	} else if (typeid(expr) == typeid(const StructDeclaration&)) {
	} else
		throw runtime_error("Not implemented");
}




Bytecode Compiler::compile(const string& str) {
	auto ast = parser::parse(str);
	Declarations decls;
	decls.var_s.emplace_back();
	decls.fun_s.emplace_back();
	decls.sp = 0;
	size_t result = 0;
	BytecodeBuilder builder;
	{
		BytecodeBuilder gb;
		gb.stack_allocate(1);
		gb.less_integer_32(0, 4, 8);
		gb.inverse_boolean(8);
		gb.stack_allocate(1);
		gb.equal_32(0, 4, 0);
		gb.inverse_boolean(0);
		gb.and_boolean(0, 8);
		auto* greater = new Bytecode(gb.build());
		decls.fun_s.back()["greater" + std::string(BuiltInTypesContainer::instance().integer_4().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder lb;
		lb.less_integer_32(0, 4, 0);
		auto* greater = new Bytecode(lb.build());
		decls.fun_s.back()["less" + std::string(BuiltInTypesContainer::instance().integer_4().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder ab;
		ab.add_integer_32(0, 4);
		auto* greater = new Bytecode(ab.build());
		decls.fun_s.back()["add" + std::string(BuiltInTypesContainer::instance().integer_4().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder ab;
		ab.int32_to_u_size(8, 8);
		ab.add_ptr(0, 8);
		auto* greater = new Bytecode(ab.build());
		decls.fun_s.back()["add"+ std::string(BuiltInTypesContainer::instance().ptr().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder ab;
		ab.add_unsigned_integer_64(0, 8);
		auto* greater = new Bytecode(ab.build());
		decls.fun_s.back()["add"+ std::string(BuiltInTypesContainer::instance().ptr().name()) + std::string(BuiltInTypesContainer::instance().u_size().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder ab;
		ab.subtract_integer_32(0, 4);
		auto* greater = new Bytecode(ab.build());
		decls.fun_s.back()["subtract"+ std::string(BuiltInTypesContainer::instance().integer_4().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder ab;
		ab.multiply_integer_32(0, 4);
		auto* greater = new Bytecode(ab.build());
		decls.fun_s.back()["multiply" + std::string(BuiltInTypesContainer::instance().integer_4().name()) + std::string(BuiltInTypesContainer::instance().integer_4().name())] = (size_t)greater;
	}
	{
		BytecodeBuilder nb;
		nb.inverse_boolean(0);
		auto* nott = new Bytecode(nb.build());
		decls.fun_s.back()["not" + std::string(BuiltInTypesContainer::instance().boolean().name())] = (size_t)nott;
	}
	{
		BytecodeBuilder nb;
		nb.heap_allocate(0, 0);
		auto* nott = new Bytecode(nb.build());
		decls.fun_s.back()["malloc" + std::string(BuiltInTypesContainer::instance().u_size().name())] = (size_t)nott;
	}
	{
		BytecodeBuilder nb;
		nb.heap_free(0);
		auto* nott = new Bytecode(nb.build());
		decls.fun_s.back()["free" + std::string(BuiltInTypesContainer::instance().ptr().name())] = (size_t)nott;
	}
	{
		BytecodeBuilder nb;
		nb.memcpy(0, 8, 16);
		auto* nott = new Bytecode(nb.build());
		decls.fun_s.back()["memcpy" + std::string(BuiltInTypesContainer::instance().ptr().name()) + std::string(BuiltInTypesContainer::instance().ptr().name()) + std::string(BuiltInTypesContainer::instance().u_size().name())] = (size_t)nott;
	}

	compile_expression(builder, *ast, decls, result);
	return builder.build();
}
