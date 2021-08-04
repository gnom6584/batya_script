cmake_minimum_required(VERSION 3.16)
project(batya_script)

set(CMAKE_CXX_STANDARD 20)

add_executable(batya_script main.cpp
        resources/keywords/keys.cpp
        resources/keywords/keys.hpp
        resources/keywords/keywords.cpp
        resources/keywords/keywords.hpp
        string_utility.cpp string_utility.hpp
        bytecode/bytecode_builder.cpp
        bytecode/bytecode_builder.cpp
        bytecode/codes.cpp
        bytecode/codes.hpp
        bytecode/interpreter.cpp
        bytecode/interpreter.hpp
        bytecode/stack.cpp
        bytecode/stack.hpp ast/typing/type.cpp ast/typing/type.hpp ast/typing/common_type.cpp ast/typing/common_type.hpp ast/expression.cpp ast/expression.hpp ast/expression_block.cpp ast/expression_block.hpp ast/declarations/declaration.cpp ast/declarations/declaration.hpp ast/declarations/variable_declaration.cpp ast/declarations/variable_declaration.hpp ast/while.cpp ast/while.hpp ast/condition.cpp ast/condition.hpp ast/assignment.cpp ast/assignment.hpp ast/typing/built_in_types_container.cpp ast/typing/built_in_types_container.hpp ast/literals/literal.cpp ast/literals/literal.hpp ast/literals/integer_literal.cpp ast/literals/integer_literal.hpp ast/literals/boolean_literal.cpp ast/literals/boolean_literal.hpp ast/parser/parser.cpp ast/parser/parser.hpp ast/parser/token.cpp ast/parser/token.hpp utility/single_pointer.cpp utility/single_pointer.hpp utility/indexed_container.cpp utility/indexed_container.hpp ast/declaration_reference.cpp ast/declaration_reference.hpp ast/declarations/function_declaration.cpp ast/declarations/function_declaration.hpp ast/function_invocation.cpp ast/function_invocation.hpp compiler/compiler.cpp compiler/compiler.hpp ast/address.cpp ast/address.hpp ast/function_signature.cpp ast/function_signature.hpp ast/literals/long_literal.cpp ast/literals/long_literal.hpp ast/literals/usize_literal.cpp ast/literals/usize_literal.hpp ast/declarations/struct_declaration.cpp ast/declarations/struct_declaration.hpp ast/typing/type_holder.cpp ast/typing/type_holder.hpp)