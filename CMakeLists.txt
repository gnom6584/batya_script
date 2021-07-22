cmake_minimum_required(VERSION 3.16)
project(batya_script)

set(CMAKE_CXX_STANDARD 20)

add_executable(batya_script main.cpp string_utility.cpp string_utility.hpp
        bytecode/bytecode_builder.cpp
        bytecode/bytecode_builder.cpp
        bytecode/codes.hpp
        bytecode/interpreter.cpp
        bytecode/interpreter.hpp
        bytecode/stack.cpp
        bytecode/stack.hpp)