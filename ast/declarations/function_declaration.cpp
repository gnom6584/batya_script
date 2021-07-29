//
// Created by Name on 27.07.2021.
//

#include "function_declaration.hpp"
#include "../typing/built_in_types_container.hpp"
#include <functional>
#include <set>

using namespace batya_script;
using namespace ast;
using namespace typing;
using namespace std;
using namespace declarations;


FunctionDeclaration::FunctionDeclaration(string name, vector<pair<string, reference_wrapper<const Type>>> parameters, const Type& return_type) noexcept(false)
	: Expression(BuiltInTypesContainer::instance().nothing()), _name(move(name)), _parameters(move(parameters)), _return_type(return_type) {

	set<string> parameters_names;

	for(const auto& parameter : _parameters) {
		if(parameters_names.count(parameter.first))
			throw runtime_error("Repeated parameter name: " + parameter.first);
		parameters_names.emplace(parameter.first);
	}

}


const string& FunctionDeclaration::name() const noexcept(true) {
	return _name;
}


const vector<pair<string, reference_wrapper<const Type>>>& FunctionDeclaration::parameters() const noexcept(true) {
	return _parameters;
}


const Type& FunctionDeclaration::return_type() const noexcept(true) {
	return _return_type;
}
