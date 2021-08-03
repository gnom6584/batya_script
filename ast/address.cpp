//
// Created by Name on 01.08.2021.
//

#include "address.hpp"

#include "typing/built_in_types_container.hpp"

batya_script::ast::Address::Address(batya_script::utility::SinglePointer<batya_script::ast::Expression> reference) noexcept(true)
	: Expression(typing::BuiltInTypesContainer::instance().ptr()), _reference(std::move(reference)) {

}


const batya_script::ast::DeclarationReference& batya_script::ast::Address::declaration_reference() const noexcept(true) {
	return dynamic_cast<const batya_script::ast::DeclarationReference&>(*_reference);
}
