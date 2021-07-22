//
// Created by Name on 20.07.2021.
//

#ifndef BATYA_SCRIPT_INTERPRETER_STACK_HPP_
#define BATYA_SCRIPT_INTERPRETER_STACK_HPP_

#include <vector>

namespace batya_script::bytecode {

class Stack final {
public:
	explicit Stack(size_t size) noexcept(true);

	Stack(const Stack&) = delete;

	Stack& operator=(const Stack&) = delete;

	~Stack() noexcept(true);

	[[nodiscard]] size_t size() const noexcept(true);

	[[nodiscard]] void* allocate(size_t bytes) noexcept(false);

	[[nodiscard]] size_t header() const noexcept(true);

	[[nodiscard]] unsigned char* bytes() const noexcept(true);

	void free(size_t bytes) noexcept(true);

private:

	unsigned char* _bytes;

	size_t _header;

	size_t _size;
};

}

#endif //BATYA_SCRIPT_INTERPRETER_STACK_HPP_
