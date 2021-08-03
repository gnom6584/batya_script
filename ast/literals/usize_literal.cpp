//
// Created by Name on 02.08.2021.
//

#include "usize_literal.hpp"

#include "../typing/built_in_types_container.hpp"

batya_script::ast::literals::USizeLiteral::USizeLiteral(size_t value) noexcept(true)
	: Literal(typing::BuiltInTypesContainer::instance().u_size()), _value(value) {

}


size_t batya_script::ast::literals::USizeLiteral::value() const noexcept(true) {
	return _value;
}
