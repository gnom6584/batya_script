//
// Created by Name on 27.07.2021.
//

#include "function_invocation.hpp"

#include <stdexcept>
#include <functional>

using namespace std;
using namespace batya_script;
using namespace utility;
using namespace ast;
using namespace typing;
using namespace declarations;


FunctionInvocation::FunctionInvocation(const FunctionDeclaration& declaration, std::vector<SinglePointer<Expression>> args) noexcept(false)
	: Expression(declaration.return_type()), _declaration(declaration), _arguments(move(args)) {

	for(auto i = 0; i < size(_arguments); ++i)
		if(_arguments[i]->result_type() != _declaration.parameters()[i].second)
			throw runtime_error("Invalid function invocation args");

}


const vector<SinglePointer<Expression>>& FunctionInvocation::arguments() const noexcept(true) {
	return _arguments;
}


const FunctionDeclaration& FunctionInvocation::declaration() const noexcept(true)  {
	return _declaration;
}
