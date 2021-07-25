#include "bytecode_builder.hpp"

#include <cstring>
#include "codes.hpp"

using namespace batya_script::bytecode;

BytecodeBuilder::BytecodeBuilder() noexcept(true)
    : _bytecode({}), _position(0) {}


size_t BytecodeBuilder::position() const noexcept(true) {
    return _position;
}


Bytecode BytecodeBuilder::build() noexcept(true) {
    auto result = Bytecode(std::move(_bytecode));
    _bytecode = {};
    _position = 0;
    return result;

}


void BytecodeBuilder::append(const Bytecode& other_bytecode) noexcept(true) {
_bytecode.insert(std::end(_bytecode), std::begin(other_bytecode), std::end(other_bytecode));
_position += std::size(other_bytecode);
}


void BytecodeBuilder::stack_allocate(size_t n_bytes) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::stack_allocate);
    for(size_t i = 0; i < codes::size_of[codes::stack_allocate]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &n_bytes, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::stack_free(size_t n_bytes) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::stack_free);
    for(size_t i = 0; i < codes::size_of[codes::stack_free]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &n_bytes, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::heap_allocate(size_t n_bytes, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::heap_allocate);
    for(size_t i = 0; i < codes::size_of[codes::heap_allocate]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &n_bytes, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::heap_free(size_t address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::heap_free);
    for(size_t i = 0; i < codes::size_of[codes::heap_free]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::stack_push() noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::stack_push);
    for(size_t i = 0; i < codes::size_of[codes::stack_push]; ++i)
        _bytecode.emplace_back();
}


void BytecodeBuilder::stack_pop() noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::stack_pop);
    for(size_t i = 0; i < codes::size_of[codes::stack_pop]; ++i)
        _bytecode.emplace_back();
}


void BytecodeBuilder::go_to(size_t position) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::go_to);
    for(size_t i = 0; i < codes::size_of[codes::go_to]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &position, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::go_to_if(size_t flag_address, size_t position) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::go_to_if);
    for(size_t i = 0; i < codes::size_of[codes::go_to_if]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &flag_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &position, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::execute_byte_code(size_t byte_code_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::execute_byte_code);
    for(size_t i = 0; i < codes::size_of[codes::execute_byte_code]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &byte_code_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::copy(size_t destination_address, size_t source_address, size_t n_bytes) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::copy);
    for(size_t i = 0; i < codes::size_of[codes::copy]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &n_bytes, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::equal(size_t destination_address, size_t source_address, size_t out_address, size_t n_bytes) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::equal);
    for(size_t i = 0; i < codes::size_of[codes::equal]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &n_bytes, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::copy_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::copy_8);
    for(size_t i = 0; i < codes::size_of[codes::copy_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::equal_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::equal_8);
    for(size_t i = 0; i < codes::size_of[codes::equal_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::copy_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::copy_16);
    for(size_t i = 0; i < codes::size_of[codes::copy_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::equal_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::equal_16);
    for(size_t i = 0; i < codes::size_of[codes::equal_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::copy_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::copy_32);
    for(size_t i = 0; i < codes::size_of[codes::copy_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::equal_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::equal_32);
    for(size_t i = 0; i < codes::size_of[codes::equal_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::copy_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::copy_64);
    for(size_t i = 0; i < codes::size_of[codes::copy_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::equal_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::equal_64);
    for(size_t i = 0; i < codes::size_of[codes::equal_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::and_boolean(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::and_boolean);
    for(size_t i = 0; i < codes::size_of[codes::and_boolean]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::or_boolean(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::or_boolean);
    for(size_t i = 0; i < codes::size_of[codes::or_boolean]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::set_boolean(size_t address, bool value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_boolean);
    for(size_t i = 0; i < codes::size_of[codes::set_boolean]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(bool));
   _position += sizeof(bool);
}


void BytecodeBuilder::set_integer_8(size_t address, char value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::set_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(char));
   _position += sizeof(char);
}


void BytecodeBuilder::set_unsigned_integer_8(size_t address, unsigned char value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::set_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(unsigned char));
   _position += sizeof(unsigned char);
}


void BytecodeBuilder::set_integer_16(size_t address, short value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::set_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(short));
   _position += sizeof(short);
}


void BytecodeBuilder::set_unsigned_integer_16(size_t address, unsigned short value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::set_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(unsigned short));
   _position += sizeof(unsigned short);
}


void BytecodeBuilder::set_integer_32(size_t address, int value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::set_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(int));
   _position += sizeof(int);
}


void BytecodeBuilder::set_unsigned_integer_32(size_t address, unsigned int value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::set_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(unsigned int));
   _position += sizeof(unsigned int);
}


void BytecodeBuilder::set_integer_64(size_t address, long long int value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::set_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(long long int));
   _position += sizeof(long long int);
}


void BytecodeBuilder::set_unsigned_integer_64(size_t address, unsigned long long int value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::set_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(unsigned long long int));
   _position += sizeof(unsigned long long int);
}


void BytecodeBuilder::set_float_32(size_t address, float value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_float_32);
    for(size_t i = 0; i < codes::size_of[codes::set_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(float));
   _position += sizeof(float);
}


void BytecodeBuilder::set_float_64(size_t address, double value) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::set_float_64);
    for(size_t i = 0; i < codes::size_of[codes::set_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &value, sizeof(double));
   _position += sizeof(double);
}


void BytecodeBuilder::less_integer_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::less_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_unsigned_integer_8(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::less_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_integer_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::less_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_unsigned_integer_16(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::less_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_integer_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::less_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_unsigned_integer_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::less_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_integer_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::less_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_unsigned_integer_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::less_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_float_32(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_float_32);
    for(size_t i = 0; i < codes::size_of[codes::less_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::less_float_64(size_t destination_address, size_t source_address, size_t out_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::less_float_64);
    for(size_t i = 0; i < codes::size_of[codes::less_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &out_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::add_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::add_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::add_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::add_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::add_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::add_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::add_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::add_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_float_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_float_32);
    for(size_t i = 0; i < codes::size_of[codes::add_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::add_float_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::add_float_64);
    for(size_t i = 0; i < codes::size_of[codes::add_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::subtract_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::subtract_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::subtract_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::subtract_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::subtract_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::subtract_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::subtract_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::subtract_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_float_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_float_32);
    for(size_t i = 0; i < codes::size_of[codes::subtract_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::subtract_float_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::subtract_float_64);
    for(size_t i = 0; i < codes::size_of[codes::subtract_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::multiply_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::multiply_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::multiply_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::multiply_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::multiply_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::multiply_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::multiply_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::multiply_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_float_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_float_32);
    for(size_t i = 0; i < codes::size_of[codes::multiply_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::multiply_float_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::multiply_float_64);
    for(size_t i = 0; i < codes::size_of[codes::multiply_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::divide_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::divide_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::divide_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::divide_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::divide_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::divide_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::divide_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::divide_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_float_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_float_32);
    for(size_t i = 0; i < codes::size_of[codes::divide_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::divide_float_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::divide_float_64);
    for(size_t i = 0; i < codes::size_of[codes::divide_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::modulus_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_unsigned_integer_8(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_unsigned_integer_8);
    for(size_t i = 0; i < codes::size_of[codes::modulus_unsigned_integer_8]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::modulus_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_unsigned_integer_16(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_unsigned_integer_16);
    for(size_t i = 0; i < codes::size_of[codes::modulus_unsigned_integer_16]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::modulus_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_unsigned_integer_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_unsigned_integer_32);
    for(size_t i = 0; i < codes::size_of[codes::modulus_unsigned_integer_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::modulus_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_unsigned_integer_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_unsigned_integer_64);
    for(size_t i = 0; i < codes::size_of[codes::modulus_unsigned_integer_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_float_32(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_float_32);
    for(size_t i = 0; i < codes::size_of[codes::modulus_float_32]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::modulus_float_64(size_t destination_address, size_t source_address) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::modulus_float_64);
    for(size_t i = 0; i < codes::size_of[codes::modulus_float_64]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &destination_address, sizeof(size_t));
   _position += sizeof(size_t);
    memcpy(_bytecode.data() + _position, &source_address, sizeof(size_t));
   _position += sizeof(size_t);
}


void BytecodeBuilder::signal(const char* msg) noexcept(true) {
    ++_position;
    _bytecode.emplace_back(codes::signal);
    for(size_t i = 0; i < codes::size_of[codes::signal]; ++i)
        _bytecode.emplace_back();
    memcpy(_bytecode.data() + _position, &msg, sizeof(const char*));
   _position += sizeof(const char*);
}