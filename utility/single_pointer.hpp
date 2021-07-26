//
// Created by Name on 25.07.2021.
//

#ifndef BATYA_SCRIPT_UTILITY_SINGLE_POINTER_HPP_
#define BATYA_SCRIPT_UTILITY_SINGLE_POINTER_HPP_

#include <utility>

namespace batya_script::utility {

template <class T>
class SinglePointer final {
public:

	template <typename ...Args>
	inline constexpr static SinglePointer<T> make(Args&&... args) noexcept(false);

	template <typename TDerived, typename ...Args>
	inline constexpr static SinglePointer<T> make_derived(Args&&... args) noexcept(false);

	inline constexpr SinglePointer(const SinglePointer& pointer) = delete;

	inline constexpr SinglePointer& operator=(const SinglePointer& pointer) = delete;

	inline constexpr SinglePointer(SinglePointer&& single_pointer) noexcept(true);

	inline constexpr SinglePointer& operator=(SinglePointer&& single_pointer) noexcept(true);

	inline ~SinglePointer() noexcept(true);

	inline constexpr T* operator->() noexcept(true);

	inline constexpr const T* operator->() const noexcept(true);

	[[nodiscard]] inline constexpr T& operator*() noexcept(true);

	[[nodiscard]] inline constexpr const T& operator*() const noexcept(true);

	[[nodiscard]] inline constexpr bool is_valid() const noexcept(true);

	explicit inline constexpr SinglePointer(T* pointer);
private:

	T* _pointer;
};


//////////////////////////////////////////////////////
//                  Implementation                  //
//////////////////////////////////////////////////////


template <class T>
inline constexpr SinglePointer<T>::SinglePointer(T* pointer) : _pointer(pointer) {

}


template <class T>
inline constexpr SinglePointer<T>::SinglePointer(SinglePointer&& single_pointer) noexcept(true) : _pointer(single_pointer._pointer) {
	single_pointer._pointer = nullptr;
}


template <class T>
inline constexpr SinglePointer<T>& SinglePointer<T>::operator=(SinglePointer&& single_pointer) noexcept(true) {
	_pointer = single_pointer._pointer;
	single_pointer._pointer = nullptr;
	return *this;
}


template <class T>
inline SinglePointer<T>::~SinglePointer() noexcept(true) {
	if (_pointer != nullptr)
		delete _pointer;
}


template <class T>
inline constexpr T* SinglePointer<T>::operator->() noexcept(true) {
	return _pointer;
}


template <class T>
inline constexpr const T* SinglePointer<T>::operator->() const noexcept(true) {
	return _pointer;
}


template <class T>
inline constexpr T& SinglePointer<T>::operator*() noexcept(true) {
	return *_pointer;
}


template <class T>
inline constexpr const T& SinglePointer<T>::operator*() const noexcept(true) {
	return *_pointer;
}


template <class T>
constexpr bool SinglePointer<T>::is_valid() const noexcept(true) {
	return _pointer != nullptr;
}


template <class T>
template <typename... Args>
constexpr SinglePointer<T> SinglePointer<T>::make(Args&& ... args) noexcept(false) {
	return SinglePointer<T>(new T(std::forward<Args>(args)...));
}


template <class T>
template <typename TDerived, typename... Args>
constexpr SinglePointer<T> SinglePointer<T>::make_derived(Args&&... args) noexcept(false) {
	return SinglePointer<T>(new TDerived(std::forward<Args>(args)...));
}

}

#endif //BATYA_SCRIPT_UTILITY_SINGLE_POINTER_HPP_
