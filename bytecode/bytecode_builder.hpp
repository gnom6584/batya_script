//
// Created by batya on 24.07.2021.
//

#ifndef BATYA_SCRIPT_BYTECODE_BYTECODE_BUILDER_HPP_
#define BATYA_SCRIPT_BYTECODE_BYTECODE_BUILDER_HPP_

#include <vector>

namespace batya_script::bytecode {

using Bytecode = std::vector<unsigned char>;

class BytecodeBuilder {
public:

    BytecodeBuilder() noexcept(true);

    [[nodiscard]] size_t position() const noexcept(true);

    [[nodiscard]] Bytecode build() noexcept(true);

    void append(const Bytecode& other_bytecode) noexcept(true);

    void stack_allocate(size_t n_bytes) noexcept(true); 

    void stack_free(size_t n_bytes) noexcept(true); 

    void heap_allocate(size_t n_bytes, size_t out_address) noexcept(true); 

    void heap_free(size_t address) noexcept(true); 

    void stack_push() noexcept(true); 

    void stack_pop() noexcept(true); 

    void go_to(size_t position) noexcept(true); 

    void go_to_if(size_t flag_address, size_t position) noexcept(true); 

    void execute_byte_code(size_t byte_code_address) noexcept(true); 

    void copy(size_t destination_address, size_t source_address, size_t n_bytes) noexcept(true); 

    void equal(size_t destination_address, size_t source_address, size_t out_address, size_t n_bytes) noexcept(true); 

    void copy_8(size_t destination_address, size_t source_address) noexcept(true); 

    void equal_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void copy_16(size_t destination_address, size_t source_address) noexcept(true); 

    void equal_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void copy_32(size_t destination_address, size_t source_address) noexcept(true); 

    void equal_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void copy_64(size_t destination_address, size_t source_address) noexcept(true); 

    void equal_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void and_boolean(size_t destination_address, size_t source_address) noexcept(true); 

    void or_boolean(size_t destination_address, size_t source_address) noexcept(true); 

    void set_boolean(size_t address, bool value) noexcept(true); 

    void set_integer_8(size_t address, char value) noexcept(true); 

    void set_unsigned_integer_8(size_t address, unsigned char value) noexcept(true); 

    void set_integer_16(size_t address, short value) noexcept(true); 

    void set_unsigned_integer_16(size_t address, unsigned short value) noexcept(true); 

    void set_integer_32(size_t address, int value) noexcept(true); 

    void set_unsigned_integer_32(size_t address, unsigned int value) noexcept(true); 

    void set_integer_64(size_t address, long long int value) noexcept(true); 

    void set_unsigned_integer_64(size_t address, unsigned long long int value) noexcept(true); 

    void set_float_32(size_t address, float value) noexcept(true); 

    void set_float_64(size_t address, double value) noexcept(true); 

    void less_integer_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_unsigned_integer_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_integer_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_unsigned_integer_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_integer_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_unsigned_integer_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_integer_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_unsigned_integer_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_float_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void less_float_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true); 

    void add_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void add_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void add_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void add_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void add_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void add_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void add_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void add_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void add_float_32(size_t destination_address, size_t source_address) noexcept(true); 

    void add_float_64(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_float_32(size_t destination_address, size_t source_address) noexcept(true); 

    void subtract_float_64(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_float_32(size_t destination_address, size_t source_address) noexcept(true); 

    void multiply_float_64(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_float_32(size_t destination_address, size_t source_address) noexcept(true); 

    void divide_float_64(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_float_32(size_t destination_address, size_t source_address) noexcept(true); 

    void modulus_float_64(size_t destination_address, size_t source_address) noexcept(true); 

    void signal(const char* msg) noexcept(true); 

private:

    Bytecode _bytecode;

    size_t _position;

};

}

#endif //BATYA_SCRIPT_BYTECODE_BYTECODE_BUILDER_HPP_