//
// Created by Name on 03.08.2021.
//

#ifndef BATYA_SCRIPT_BYTECODE_CODES_HPP_
#define BATYA_SCRIPT_BYTECODE_CODES_HPP_

#include <array>

namespace batya_script::bytecode::codes {

constexpr inline unsigned char stack_allocate = 0;

constexpr inline unsigned char stack_free = 1;

constexpr inline unsigned char heap_allocate = 2;

constexpr inline unsigned char heap_free = 3;

constexpr inline unsigned char memcpy = 4;

constexpr inline unsigned char address_from_stack = 5;

constexpr inline unsigned char stack_push = 6;

constexpr inline unsigned char stack_pop = 7;

constexpr inline unsigned char go_to = 8;

constexpr inline unsigned char go_to_if = 9;

constexpr inline unsigned char execute_byte_code = 10;

constexpr inline unsigned char copy = 11;

constexpr inline unsigned char equal = 12;

constexpr inline unsigned char copy_8 = 13;

constexpr inline unsigned char equal_8 = 14;

constexpr inline unsigned char copy_16 = 15;

constexpr inline unsigned char equal_16 = 16;

constexpr inline unsigned char copy_32 = 17;

constexpr inline unsigned char equal_32 = 18;

constexpr inline unsigned char copy_64 = 19;

constexpr inline unsigned char equal_64 = 20;

constexpr inline unsigned char inverse_boolean = 21;

constexpr inline unsigned char and_boolean = 22;

constexpr inline unsigned char or_boolean = 23;

constexpr inline unsigned char set_boolean = 24;

constexpr inline unsigned char set_integer_8 = 25;

constexpr inline unsigned char set_unsigned_integer_8 = 26;

constexpr inline unsigned char set_integer_16 = 27;

constexpr inline unsigned char set_unsigned_integer_16 = 28;

constexpr inline unsigned char set_integer_32 = 29;

constexpr inline unsigned char set_unsigned_integer_32 = 30;

constexpr inline unsigned char set_integer_64 = 31;

constexpr inline unsigned char set_unsigned_integer_64 = 32;

constexpr inline unsigned char set_float_32 = 33;

constexpr inline unsigned char set_float_64 = 34;

constexpr inline unsigned char set_ptr = 35;

constexpr inline unsigned char set_usize = 36;

constexpr inline unsigned char less_integer_8 = 37;

constexpr inline unsigned char less_unsigned_integer_8 = 38;

constexpr inline unsigned char less_integer_16 = 39;

constexpr inline unsigned char less_unsigned_integer_16 = 40;

constexpr inline unsigned char less_integer_32 = 41;

constexpr inline unsigned char less_unsigned_integer_32 = 42;

constexpr inline unsigned char less_integer_64 = 43;

constexpr inline unsigned char less_unsigned_integer_64 = 44;

constexpr inline unsigned char less_float_32 = 45;

constexpr inline unsigned char less_float_64 = 46;

constexpr inline unsigned char less_ptr = 47;

constexpr inline unsigned char less_usize = 48;

constexpr inline unsigned char add_integer_8 = 49;

constexpr inline unsigned char add_unsigned_integer_8 = 50;

constexpr inline unsigned char add_integer_16 = 51;

constexpr inline unsigned char add_unsigned_integer_16 = 52;

constexpr inline unsigned char add_integer_32 = 53;

constexpr inline unsigned char add_unsigned_integer_32 = 54;

constexpr inline unsigned char add_integer_64 = 55;

constexpr inline unsigned char add_unsigned_integer_64 = 56;

constexpr inline unsigned char add_float_32 = 57;

constexpr inline unsigned char add_float_64 = 58;

constexpr inline unsigned char add_ptr = 59;

constexpr inline unsigned char add_usize = 60;

constexpr inline unsigned char subtract_integer_8 = 61;

constexpr inline unsigned char subtract_unsigned_integer_8 = 62;

constexpr inline unsigned char subtract_integer_16 = 63;

constexpr inline unsigned char subtract_unsigned_integer_16 = 64;

constexpr inline unsigned char subtract_integer_32 = 65;

constexpr inline unsigned char subtract_unsigned_integer_32 = 66;

constexpr inline unsigned char subtract_integer_64 = 67;

constexpr inline unsigned char subtract_unsigned_integer_64 = 68;

constexpr inline unsigned char subtract_float_32 = 69;

constexpr inline unsigned char subtract_float_64 = 70;

constexpr inline unsigned char subtract_ptr = 71;

constexpr inline unsigned char subtract_usize = 72;

constexpr inline unsigned char multiply_integer_8 = 73;

constexpr inline unsigned char multiply_unsigned_integer_8 = 74;

constexpr inline unsigned char multiply_integer_16 = 75;

constexpr inline unsigned char multiply_unsigned_integer_16 = 76;

constexpr inline unsigned char multiply_integer_32 = 77;

constexpr inline unsigned char multiply_unsigned_integer_32 = 78;

constexpr inline unsigned char multiply_integer_64 = 79;

constexpr inline unsigned char multiply_unsigned_integer_64 = 80;

constexpr inline unsigned char multiply_float_32 = 81;

constexpr inline unsigned char multiply_float_64 = 82;

constexpr inline unsigned char multiply_ptr = 83;

constexpr inline unsigned char multiply_usize = 84;

constexpr inline unsigned char divide_integer_8 = 85;

constexpr inline unsigned char divide_unsigned_integer_8 = 86;

constexpr inline unsigned char divide_integer_16 = 87;

constexpr inline unsigned char divide_unsigned_integer_16 = 88;

constexpr inline unsigned char divide_integer_32 = 89;

constexpr inline unsigned char divide_unsigned_integer_32 = 90;

constexpr inline unsigned char divide_integer_64 = 91;

constexpr inline unsigned char divide_unsigned_integer_64 = 92;

constexpr inline unsigned char divide_float_32 = 93;

constexpr inline unsigned char divide_float_64 = 94;

constexpr inline unsigned char divide_ptr = 95;

constexpr inline unsigned char divide_usize = 96;

constexpr inline unsigned char modulus_integer_8 = 97;

constexpr inline unsigned char modulus_unsigned_integer_8 = 98;

constexpr inline unsigned char modulus_integer_16 = 99;

constexpr inline unsigned char modulus_unsigned_integer_16 = 100;

constexpr inline unsigned char modulus_integer_32 = 101;

constexpr inline unsigned char modulus_unsigned_integer_32 = 102;

constexpr inline unsigned char modulus_integer_64 = 103;

constexpr inline unsigned char modulus_unsigned_integer_64 = 104;

constexpr inline unsigned char modulus_float_32 = 105;

constexpr inline unsigned char modulus_float_64 = 106;

constexpr inline unsigned char modulus_ptr = 107;

constexpr inline unsigned char modulus_usize = 108;

constexpr inline unsigned char float64_to_float32 = 109;

constexpr inline unsigned char float64_to_int32 = 110;

constexpr inline unsigned char float64_to_int64 = 111;

constexpr inline unsigned char float32_to_float64 = 112;

constexpr inline unsigned char float32_to_int32 = 113;

constexpr inline unsigned char float32_to_int64 = 114;

constexpr inline unsigned char int32_to_int8 = 115;

constexpr inline unsigned char int32_to_unsigned_int8 = 116;

constexpr inline unsigned char int32_to_int64 = 117;

constexpr inline unsigned char int32_to_int16 = 118;

constexpr inline unsigned char int32_to_float64 = 119;

constexpr inline unsigned char int32_to_float32 = 120;

constexpr inline unsigned char int32_to_u_size = 121;

constexpr inline unsigned char int64_to_ptr = 122;

constexpr inline unsigned char ptr_to_int64 = 123;

constexpr inline unsigned char signal = 124;

constexpr std::array<unsigned char, 125> size_of {
/*stack_allocate*/ sizeof(size_t),
/*stack_free*/ sizeof(size_t),
/*heap_allocate*/ sizeof(size_t) + sizeof(size_t),
/*heap_free*/ sizeof(size_t),
/*memcpy*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
/*address_from_stack*/ sizeof(size_t) + sizeof(size_t),
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
/*inverse_boolean*/ sizeof(size_t),
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
/*set_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*set_usize*/ sizeof(size_t) + sizeof(size_t),
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
/*less_ptr*/ sizeof(size_t) + sizeof(uintptr_t) + sizeof(size_t),
/*less_usize*/ sizeof(size_t) + sizeof(size_t) + sizeof(size_t),
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
/*add_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*add_usize*/ sizeof(size_t) + sizeof(size_t),
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
/*subtract_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*subtract_usize*/ sizeof(size_t) + sizeof(size_t),
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
/*multiply_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*multiply_usize*/ sizeof(size_t) + sizeof(size_t),
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
/*divide_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*divide_usize*/ sizeof(size_t) + sizeof(size_t),
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
/*modulus_ptr*/ sizeof(size_t) + sizeof(uintptr_t),
/*modulus_usize*/ sizeof(size_t) + sizeof(size_t),
/*float64_to_float32*/ sizeof(size_t) + sizeof(size_t),
/*float64_to_int32*/ sizeof(size_t) + sizeof(size_t),
/*float64_to_int64*/ sizeof(size_t) + sizeof(size_t),
/*float32_to_float64*/ sizeof(size_t) + sizeof(size_t),
/*float32_to_int32*/ sizeof(size_t) + sizeof(size_t),
/*float32_to_int64*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_int8*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_unsigned_int8*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_int64*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_int16*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_float64*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_float32*/ sizeof(size_t) + sizeof(size_t),
/*int32_to_u_size*/ sizeof(size_t) + sizeof(size_t),
/*int64_to_ptr*/ sizeof(size_t) + sizeof(size_t),
/*ptr_to_int64*/ sizeof(size_t) + sizeof(size_t),
/*signal*/ sizeof(const char*)
};

constexpr std::array<const char*, 125> spelling_of {
/*stack_allocate*/ "stack_allocate",
/*stack_free*/ "stack_free",
/*heap_allocate*/ "heap_allocate",
/*heap_free*/ "heap_free",
/*memcpy*/ "memcpy",
/*address_from_stack*/ "address_from_stack",
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
/*inverse_boolean*/ "inverse_boolean",
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
/*set_ptr*/ "set_ptr",
/*set_usize*/ "set_usize",
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
/*less_ptr*/ "less_ptr",
/*less_usize*/ "less_usize",
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
/*add_ptr*/ "add_ptr",
/*add_usize*/ "add_usize",
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
/*subtract_ptr*/ "subtract_ptr",
/*subtract_usize*/ "subtract_usize",
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
/*multiply_ptr*/ "multiply_ptr",
/*multiply_usize*/ "multiply_usize",
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
/*divide_ptr*/ "divide_ptr",
/*divide_usize*/ "divide_usize",
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
/*modulus_ptr*/ "modulus_ptr",
/*modulus_usize*/ "modulus_usize",
/*float64_to_float32*/ "float64_to_float32",
/*float64_to_int32*/ "float64_to_int32",
/*float64_to_int64*/ "float64_to_int64",
/*float32_to_float64*/ "float32_to_float64",
/*float32_to_int32*/ "float32_to_int32",
/*float32_to_int64*/ "float32_to_int64",
/*int32_to_int8*/ "int32_to_int8",
/*int32_to_unsigned_int8*/ "int32_to_unsigned_int8",
/*int32_to_int64*/ "int32_to_int64",
/*int32_to_int16*/ "int32_to_int16",
/*int32_to_float64*/ "int32_to_float64",
/*int32_to_float32*/ "int32_to_float32",
/*int32_to_u_size*/ "int32_to_u_size",
/*int64_to_ptr*/ "int64_to_ptr",
/*ptr_to_int64*/ "ptr_to_int64",
/*signal*/ "signal"
};

[[nodiscard]] std::string dump_command(const unsigned char* ptr) noexcept(false);
}

#endif //BATYA_SCRIPT_BYTECODE_CODES_HPP_