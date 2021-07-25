//
// Created by Name on 24.07.2021.
//

#ifndef BATYA_SCRIPT_AST_DECLARATIONS_DECLARATION_HPP_
#define BATYA_SCRIPT_AST_DECLARATIONS_DECLARATION_HPP_

#include "../expression.hpp"

namespace batya_script::ast::declarations {

class Declaration : public Expression {
public:
	explicit Declaration(const typing::Type& result_type) noexcept(true);
};

}

#endif //BATYA_SCRIPT_AST_DECLARATIONS_DECLARATION_HPP_
