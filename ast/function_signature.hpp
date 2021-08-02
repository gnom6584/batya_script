//
// Created by Name on 02.08.2021.
//

#ifndef BATYA_SCRIPT_AST_FUNCTION_SIGNATURE_HPP_
#define BATYA_SCRIPT_AST_FUNCTION_SIGNATURE_HPP_

#include <string>
#include <vector>
#include <functional>
#include "typing/type.hpp"

namespace batya_script::ast {

class FunctionSignature {
public:

	FunctionSignature() = default;

	FunctionSignature(std::string name, std::vector<std::string> parameters/*, const typing::Type& return_type*/) noexcept(true);

	[[nodiscard]] bool operator<(const FunctionSignature& function_signature) const noexcept(true);

	[[nodiscard]] const std::string& name() const noexcept(true);

	[[nodiscard]] const std::vector<std::string>& parameters() const noexcept(true);

	//[[nodiscard]] const typing::Type& return_type() const noexcept(true);

private:

	std::string _name;

	std::vector<std::string> _parameters;

//	const typing::Type& _return_type;
};

}

#endif //BATYA_SCRIPT_AST_FUNCTION_SIGNATURE_HPP_
