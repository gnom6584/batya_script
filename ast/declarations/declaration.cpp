//
// Created by Name on 24.07.2021.
//

#include "declaration.hpp"


batya_script::ast::declarations::Declaration::Declaration(const batya_script::ast::typing::Type& result_type) noexcept(true) : Expression(result_type) {

}
