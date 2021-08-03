#include <iostream>
#include <cstring>
#include <stack>
#include <map>

#include "bytecode/bytecode_builder.hpp"
#include "bytecode/interpreter.hpp"
#include "bytecode/codes.hpp"

#include "string_utility.hpp"

#include <list>
#include <utility>
#include <sstream>

#include "ast/assignment.hpp"
#include "ast/binary_operator.hpp"
#include "ast/condition.hpp"
#include "ast/declarations/declaration.hpp"
#include "ast/declarations/function_declaration.hpp"
#include "ast/declarations/variable_declaration.hpp"
#include "ast/declaration_reference.hpp"
#include "ast/expression.hpp"
#include "ast/expression_block.hpp"
#include "ast/function_invocation.hpp"
#include "ast/literals/boolean_literal.hpp"
#include "ast/literals/integer_literal.hpp"
#include "ast/literals/literal.hpp"
#include "ast/parser/parser.hpp"
#include "ast/parser/token.hpp"
#include "ast/typing/binary_operator.hpp"
#include "ast/typing/built_in_types_container.hpp"
#include "ast/typing/common_type.hpp"
#include "ast/typing/type.hpp"
#include "ast/typing/unary_operator.hpp"
#include "ast/unary_operator.hpp"
#include "ast/while.hpp"

using namespace batya_script::ast;
using namespace batya_script::utility;
using namespace declarations;
using namespace typing;
using namespace batya_script::bytecode;

#include <fstream>
#include "compiler/compiler.hpp"

int main() {

	std::ifstream f("/mnt/c/Users/Name/CLionProjects/batya_script/test");

	std::stringstream ss;
	ss << f.rdbuf();

	auto b = batya_script::Compiler::compile(ss.str());

	const auto& bc = b;

	Stack stack(1024);
	std::stack<size_t> headers;

	Interpreter::run(bc, stack, headers);

	std::cout << stack.header() << std::endl;
	int* a = (int*)*(size_t*)(stack.bytes());
	std::cout << *(int*)(stack.bytes());;
//	for(int i = 0; i < 13; ++i) {
//		std::cout << a[i] << std::endl;
//	}
	return 0;
}
