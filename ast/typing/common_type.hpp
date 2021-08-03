//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
#define BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_

#include "type.hpp"
#include <functional>
#include <vector>

namespace batya_script::ast::typing {

class CommonType : public Type {
public:

	explicit CommonType(std::string name, size_t size, std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> fields = {}) noexcept(true);

	[[nodiscard]] const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>>& fields() const noexcept(true);

	[[nodiscard]] std::string_view name() const noexcept(true) override;

	[[nodiscard]] size_t size() const noexcept(true) override;

private:

	const std::string _name;

	const std::vector<std::pair<std::string, std::reference_wrapper<const typing::Type>>> _fields;

	const size_t _size;
};

}

#endif //BATYA_SCRIPT_AST_TYPING_COMMON_TYPE_HPP_
