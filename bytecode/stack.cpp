//
// Created by Name on 20.07.2021.
//

#include "stack.hpp"
#include <stdexcept>
#include <sstream>

using namespace batya_script::bytecode;

Stack::Stack(size_t size) noexcept(true) : _size(size), _header(0) {
	_bytes = new unsigned char[size];
}


Stack::~Stack() noexcept(true) {
	delete _bytes;
}


size_t Stack::size() const noexcept(true){
	return _size;
}


void* Stack::allocate(size_t bytes) noexcept(false) {
	if(_header + bytes >= _size) {
		std::stringstream message;
		message << "Stack overflow: ";
		message << "stack state = ";
		message << _header + bytes << "/" << _size;
		throw std::out_of_range(message.str());
	}
	auto temp = _header;
	_header += bytes;
	return (void*)(_bytes + temp);
}


void Stack::free(size_t bytes) noexcept(true) {
	_header -= bytes;
	if(_header < 0)
		_header = 0;
}


size_t Stack::header() const noexcept(true) {
	return _header;
}


unsigned char* Stack::bytes() const noexcept(true) {
	return _bytes;
}
