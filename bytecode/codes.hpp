//
// Created by batya on 24.07.2021.
//

#ifndef BATYA_SCRIPT_BYTECODE_CODES_HPP_
#define BATYA_SCRIPT_BYTECODE_CODES_HPP_

#include <array>

namespace batya_script::bytecode::codes {

constexpr inline unsigned char stack_allocate = 0;

constexpr inline unsigned char stack_free = 1;

constexpr inline unsigned char heap_allocate = 2;

constexpr inline unsigned char heap_free = 3;

constexpr inline unsigned char stack_push = 4;

constexpr inline unsigned char stack_pop = 5;

constexpr inline unsigned char go_to = 6;

constexpr inline unsigned char go_to_if = 7;

constexpr inline unsigned char execute_byte_code = 8;

constexpr inline unsigned char copy = 9;

constexpr inline unsigned char equal = 10;

constexpr inline unsigned char copy_8 = 11;

constexpr inline unsigned char equal_8 = 12;

constexpr inline unsigned char copy_16 = 13;

constexpr inline unsigned char equal_16 = 14;

constexpr inline unsigned char copy_32 = 15;

constexpr inline unsigned char equal_32 = 16;

constexpr inline unsigned char copy_64 = 17;

constexpr inline unsigned char equal_64 = 18;

constexpr inline unsigned char and_boolean = 19;

constexpr inline unsigned char or_boolean = 20;

constexpr inline unsigned char set_boolean = 21;

constexpr inline unsigned char set_integer_8 = 22;

constexpr inline unsigned char set_unsigned_integer_8 = 23;

constexpr inline unsigned char set_integer_16 = 24;

constexpr inline unsigned char set_unsigned_integer_16 = 25;

constexpr inline unsigned char set_integer_32 = 26;

constexpr inline unsigned char set_unsigned_integer_32 = 27;

constexpr inline unsigned char set_integer_64 = 28;

constexpr inline unsigned char set_unsigned_integer_64 = 29;

constexpr inline unsigned char set_float_32 = 30;

constexpr inline unsigned char set_float_64 = 31;

constexpr inline unsigned char less_integer_8 = 32;

constexpr inline unsigned char less_unsigned_integer_8 = 33;

constexpr inline unsigned char less_integer_16 = 34;

constexpr inline unsigned char less_unsigned_integer_16 = 35;

constexpr inline unsigned char less_integer_32 = 36;

constexpr inline unsigned char less_unsigned_integer_32 = 37;

constexpr inline unsigned char less_integer_64 = 38;

constexpr inline unsigned char less_unsigned_integer_64 = 39;

constexpr inline unsigned char less_float_32 = 40;

constexpr inline unsigned char less_float_64 = 41;

constexpr inline unsigned char add_integer_8 = 42;

constexpr inline unsigned char add_unsigned_integer_8 = 43;

constexpr inline unsigned char add_integer_16 = 44;

constexpr inline unsigned char add_unsigned_integer_16 = 45;

constexpr inline unsigned char add_integer_32 = 46;

constexpr inline unsigned char add_unsigned_integer_32 = 47;

constexpr inline unsigned char add_integer_64 = 48;

constexpr inline unsigned char add_unsigned_integer_64 = 49;

constexpr inline unsigned char add_float_32 = 50;

constexpr inline unsigned char add_float_64 = 51;

constexpr inline unsigned char subtract_integer_8 = 52;

constexpr inline unsigned char subtract_unsigned_integer_8 = 53;

constexpr inline unsigned char subtract_integer_16 = 54;

constexpr inline unsigned char subtract_unsigned_integer_16 = 55;

constexpr inline unsigned char subtract_integer_32 = 56;

constexpr inline unsigned char subtract_unsigned_integer_32 = 57;

constexpr inline unsigned char subtract_integer_64 = 58;

constexpr inline unsigned char subtract_unsigned_integer_64 = 59;

constexpr inline unsigned char subtract_float_32 = 60;

constexpr inline unsigned char subtract_float_64 = 61;

constexpr inline unsigned char multiply_integer_8 = 62;

constexpr inline unsigned char multiply_unsigned_integer_8 = 63;

constexpr inline unsigned char multiply_integer_16 = 64;

constexpr inline unsigned char multiply_unsigned_integer_16 = 65;

constexpr inline unsigned char multiply_integer_32 = 66;

constexpr inline unsigned char multiply_unsigned_integer_32 = 67;

constexpr inline unsigned char multiply_integer_64 = 68;

constexpr inline unsigned char multiply_unsigned_integer_64 = 69;

constexpr inline unsigned char multiply_float_32 = 70;

constexpr inline unsigned char multiply_float_64 = 71;

constexpr inline unsigned char divide_integer_8 = 72;

constexpr inline unsigned char divide_unsigned_integer_8 = 73;

constexpr inline unsigned char divide_integer_16 = 74;

constexpr inline unsigned char divide_unsigned_integer_16 = 75;

constexpr inline unsigned char divide_integer_32 = 76;

constexpr inline unsigned char divide_unsigned_integer_32 = 77;

constexpr inline unsigned char divide_integer_64 = 78;

constexpr inline unsigned char divide_unsigned_integer_64 = 79;

constexpr inline unsigned char divide_float_32 = 80;

constexpr inline unsigned char divide_float_64 = 81;

constexpr inline unsigned char modulus_integer_8 = 82;

constexpr inline unsigned char modulus_unsigned_integer_8 = 83;

constexpr inline unsigned char modulus_integer_16 = 84;

constexpr inline unsigned char modulus_unsigned_integer_16 = 85;

constexpr inline unsigned char modulus_integer_32 = 86;

constexpr inline unsigned char modulus_unsigned_integer_32 = 87;

constexpr inline unsigned char modulus_integer_64 = 88;

constexpr inline unsigned char modulus_unsigned_integer_64 = 89;

constexpr inline unsigned char modulus_float_32 = 90;

constexpr inline unsigned char modulus_float_64 = 91;

constexpr inline unsigned char signal = 92;

constexpr std::array<unsigned char, 93> size_of {
/*stack_allocate*/ sizeof(size_t),
/*stack_free*/ sizeof(size_t),
/*heap_allocate*/ sizeof(size_t) + sizeof(size_t),
/*heap_free*/ sizeof(size_t),
/*stack_push*/ 0,
/*stack_pop*/ 0,
/*go_to*/ sizeof(size_t),
/*go_to_if*/ sizeof(size_t) + sizeof(size_t),
/*execute_byte_code*/ sizeof(size_t),
/*copy*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*equal*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*copy_8*/ sizeof(size_t) + sizeof(size_t),
/*equal_8*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*copy_16*/ sizeof(size_t) + sizeof(size_t),
/*equal_16*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*copy_32*/ sizeof(size_t) + sizeof(size_t),
/*equal_32*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*copy_64*/ sizeof(size_t) + sizeof(size_t),
/*equal_64*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*and_boolean*/ sizeof(size_t) + sizeof(size_t),
/*or_boolean*/ sizeof(size_t) + sizeof(size_t),
/*set_boolean*/ sizeof(size_t) + sizeof(bool),
/*set_integer_8*/ sizeof(size_t) + sizeof(char),
/*set_unsigned_integer_8*/ sizeof(size_t) + sizeof(unsigned char),
/*set_integer_16*/ sizeof(size_t) + sizeof(short),
/*set_unsigned_integer_16*/ sizeof(size_t) + sizeof(unsigned short),
/*set_integer_32*/ sizeof(size_t) + sizeof(int),
/*set_unsigned_integer_32*/ sizeof(size_t) + sizeof(unsigned int),
/*set_integer_64*/ sizeof(size_t) + sizeof(long long int),
/*set_unsigned_integer_64*/ sizeof(size_t) + sizeof(unsigned long long int),
/*set_float_32*/ sizeof(size_t) + sizeof(float),
/*set_float_64*/ sizeof(size_t) + sizeof(double),
/*less_integer_8*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_integer_16*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_integer_32*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_integer_64*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_float_32*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*less_float_64*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*add_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*add_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*add_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*add_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*add_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*add_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*add_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*add_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*add_float_32*/ sizeof(size_t) + sizeof(size_t),
/*add_float_64*/ sizeof(size_t) + sizeof(size_t),
/*subtract_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*subtract_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*subtract_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*subtract_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*subtract_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*subtract_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*subtract_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*subtract_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*subtract_float_32*/ sizeof(size_t) + sizeof(size_t),
/*subtract_float_64*/ sizeof(size_t) + sizeof(size_t),
/*multiply_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*multiply_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*multiply_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*multiply_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*multiply_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*multiply_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*multiply_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*multiply_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*multiply_float_32*/ sizeof(size_t) + sizeof(size_t),
/*multiply_float_64*/ sizeof(size_t) + sizeof(size_t),
/*divide_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*divide_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*divide_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*divide_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*divide_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*divide_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*divide_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*divide_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*divide_float_32*/ sizeof(size_t) + sizeof(size_t),
/*divide_float_64*/ sizeof(size_t) + sizeof(size_t),
/*modulus_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*modulus_unsigned_integer_8*/ sizeof(size_t) + sizeof(size_t),
/*modulus_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*modulus_unsigned_integer_16*/ sizeof(size_t) + sizeof(size_t),
/*modulus_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*modulus_unsigned_integer_32*/ sizeof(size_t) + sizeof(size_t),
/*modulus_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*modulus_unsigned_integer_64*/ sizeof(size_t) + sizeof(size_t),
/*modulus_float_32*/ sizeof(size_t) + sizeof(size_t),
/*modulus_float_64*/ sizeof(size_t) + sizeof(size_t),
/*signal*/ sizeof(const char*)
};

constexpr std::array<const char*, 93> spelling_of {
/*stack_allocate*/ "stack_allocate",
/*stack_free*/ "stack_free",
/*heap_allocate*/ "heap_allocate",
/*heap_free*/ "heap_free",
/*stack_push*/ "stack_push",
/*stack_pop*/ "stack_pop",
/*go_to*/ "go_to",
/*go_to_if*/ "go_to_if",
/*execute_byte_code*/ "execute_byte_code",
/*copy*/ "copy",
/*equal*/ "equal",
/*copy_8*/ "copy_8",
/*equal_8*/ "equal_8",
/*copy_16*/ "copy_16",
/*equal_16*/ "equal_16",
/*copy_32*/ "copy_32",
/*equal_32*/ "equal_32",
/*copy_64*/ "copy_64",
/*equal_64*/ "equal_64",
/*and_boolean*/ "and_boolean",
/*or_boolean*/ "or_boolean",
/*set_boolean*/ "set_boolean",
/*set_integer_8*/ "set_integer_8",
/*set_unsigned_integer_8*/ "set_unsigned_integer_8",
/*set_integer_16*/ "set_integer_16",
/*set_unsigned_integer_16*/ "set_unsigned_integer_16",
/*set_integer_32*/ "set_integer_32",
/*set_unsigned_integer_32*/ "set_unsigned_integer_32",
/*set_integer_64*/ "set_integer_64",
/*set_unsigned_integer_64*/ "set_unsigned_integer_64",
/*set_float_32*/ "set_float_32",
/*set_float_64*/ "set_float_64",
/*less_integer_8*/ "less_integer_8",
/*less_unsigned_integer_8*/ "less_unsigned_integer_8",
/*less_integer_16*/ "less_integer_16",
/*less_unsigned_integer_16*/ "less_unsigned_integer_16",
/*less_integer_32*/ "less_integer_32",
/*less_unsigned_integer_32*/ "less_unsigned_integer_32",
/*less_integer_64*/ "less_integer_64",
/*less_unsigned_integer_64*/ "less_unsigned_integer_64",
/*less_float_32*/ "less_float_32",
/*less_float_64*/ "less_float_64",
/*add_integer_8*/ "add_integer_8",
/*add_unsigned_integer_8*/ "add_unsigned_integer_8",
/*add_integer_16*/ "add_integer_16",
/*add_unsigned_integer_16*/ "add_unsigned_integer_16",
/*add_integer_32*/ "add_integer_32",
/*add_unsigned_integer_32*/ "add_unsigned_integer_32",
/*add_integer_64*/ "add_integer_64",
/*add_unsigned_integer_64*/ "add_unsigned_integer_64",
/*add_float_32*/ "add_float_32",
/*add_float_64*/ "add_float_64",
/*subtract_integer_8*/ "subtract_integer_8",
/*subtract_unsigned_integer_8*/ "subtract_unsigned_integer_8",
/*subtract_integer_16*/ "subtract_integer_16",
/*subtract_unsigned_integer_16*/ "subtract_unsigned_integer_16",
/*subtract_integer_32*/ "subtract_integer_32",
/*subtract_unsigned_integer_32*/ "subtract_unsigned_integer_32",
/*subtract_integer_64*/ "subtract_integer_64",
/*subtract_unsigned_integer_64*/ "subtract_unsigned_integer_64",
/*subtract_float_32*/ "subtract_float_32",
/*subtract_float_64*/ "subtract_float_64",
/*multiply_integer_8*/ "multiply_integer_8",
/*multiply_unsigned_integer_8*/ "multiply_unsigned_integer_8",
/*multiply_integer_16*/ "multiply_integer_16",
/*multiply_unsigned_integer_16*/ "multiply_unsigned_integer_16",
/*multiply_integer_32*/ "multiply_integer_32",
/*multiply_unsigned_integer_32*/ "multiply_unsigned_integer_32",
/*multiply_integer_64*/ "multiply_integer_64",
/*multiply_unsigned_integer_64*/ "multiply_unsigned_integer_64",
/*multiply_float_32*/ "multiply_float_32",
/*multiply_float_64*/ "multiply_float_64",
/*divide_integer_8*/ "divide_integer_8",
/*divide_unsigned_integer_8*/ "divide_unsigned_integer_8",
/*divide_integer_16*/ "divide_integer_16",
/*divide_unsigned_integer_16*/ "divide_unsigned_integer_16",
/*divide_integer_32*/ "divide_integer_32",
/*divide_unsigned_integer_32*/ "divide_unsigned_integer_32",
/*divide_integer_64*/ "divide_integer_64",
/*divide_unsigned_integer_64*/ "divide_unsigned_integer_64",
/*divide_float_32*/ "divide_float_32",
/*divide_float_64*/ "divide_float_64",
/*modulus_integer_8*/ "modulus_integer_8",
/*modulus_unsigned_integer_8*/ "modulus_unsigned_integer_8",
/*modulus_integer_16*/ "modulus_integer_16",
/*modulus_unsigned_integer_16*/ "modulus_unsigned_integer_16",
/*modulus_integer_32*/ "modulus_integer_32",
/*modulus_unsigned_integer_32*/ "modulus_unsigned_integer_32",
/*modulus_integer_64*/ "modulus_integer_64",
/*modulus_unsigned_integer_64*/ "modulus_unsigned_integer_64",
/*modulus_float_32*/ "modulus_float_32",
/*modulus_float_64*/ "modulus_float_64",
/*signal*/ "signal"
};

[[nodiscard]] std::string dump_command(const unsigned char* ptr) noexcept(false);
}

#endif //BATYA_SCRIPT_BYTECODE_CODES_HPP_