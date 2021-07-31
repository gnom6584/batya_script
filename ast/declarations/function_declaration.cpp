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


FunctionDeclaration::FunctionDeclaration(string name, vector<pair<string, reference_wrapper<const Type>>> parameters, const Type& return_type, utility::SinglePointer<Expression> body) noexcept(false)
	: Expression(BuiltInTypesContainer::instance().nothing()), _name(move(name)), _parameters(move(parameters)), _return_type(return_type), _body(move(body)) {

	set<string> parameters_names;

	for(const auto& parameter : _parameters) {
		if(parameters_names.count(parameter.first))
			throw runtime_error("Repeated parameter name: " + parameter.first);
		parameters_names.emplace(parameter.first);
	}

	if(return_type != _body->result_type())
		throw runtime_error("Invalid return and body types");

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


const Expression& declarations::FunctionDeclaration::body() const noexcept(true) {
	return *_body;
}


declarations::FunctionDeclaration::FunctionDeclaration(std::string name,
													   std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> parameters,
													   const typing::Type& return_type) noexcept(false)
	: Expression(BuiltInTypesContainer::instance().nothing()), _name(move(name)), _parameters(move(parameters)), _return_type(return_type), _body(move((utility::SinglePointer<Expression>)(nullptr))) {

}
