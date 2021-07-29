//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
#define BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_

#include <map>
#include "type.hpp"
#include "binary_operator.hpp"
#include "unary_operator.hpp"

namespace batya_script::ast::typing {

class CommonType : public Type {
public:

	explicit CommonType(std::string name, size_t size) noexcept(true);

	[[nodiscard]] std::string_view name() const noexcept(true) override;

	[[nodiscard]] size_t size() const noexcept(true) override;

	void add_binary_operator(std::string sign, BinaryOperator binary_operator) noexcept(true);

	void add_unary_operator(std::string sign, UnaryOperator unary_operator) noexcept(true);

private:

	std::map<std::string, BinaryOperator> _binary_operators;

	std::map<std::string, UnaryOperator> _unary_operators;

	const std::string _name;

	const size_t _size;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
