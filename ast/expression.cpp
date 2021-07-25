//
// Created by Name on 24.07.2021.
//

#include "expression.hpp"


batya_script::ast::Expression::Expression(const batya_script::ast::typing::Type& result_type) noexcept(true)
	: _result_type(result_type){

}


const batya_script::ast::typing::Type& batya_script::ast::Expression::result_type() const noexcept(true) {
	return _result_type;
}
