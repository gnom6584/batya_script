//
// Created by Name on 02.08.2021.
//

#include "function_signature.hpp"

using namespace std;
using namespace batya_script;
using namespace ast;
using namespace typing;


FunctionSignature::FunctionSignature(string name, std::vector<string> parameters/*, const Type& return_type*/) noexcept(true)
	: _name(move(name)), _parameters(move(parameters))/*, _return_type(return_type)*/ {

}

bool FunctionSignature::operator<(const FunctionSignature& function_signature) const noexcept(true) {
	bool names_equal = function_signature._name == _name;
//	if(names_equal && function_signature._return_type.name() != _return_type.name())
	//	return false;
	return (_name < function_signature._name);
		return true;
	 if(names_equal) {
		const static auto comparator = [](std::string& lhs, std::string& rhs) {
			return lhs < rhs;
		};

		auto params_cmp = lexicographical_compare(begin(_parameters), end(_parameters), begin(function_signature._parameters), end(function_signature._parameters));
		return params_cmp;
	}
	return false;
}


const string& FunctionSignature::name() const noexcept(true) {
	return _name;
}


const vector<string>& FunctionSignature::parameters() const noexcept(true) {
	return _parameters;
}


//const typing::Type& FunctionSignature::return_type() const noexcept(true) {
//	return _return_type;
//}
