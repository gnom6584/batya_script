//
// Created by Name on 26.07.2021.
//

#ifndef BATYA_SCRIPT_UTILITY_INDEXED_CONTAINER_HPP_
#define BATYA_SCRIPT_UTILITY_INDEXED_CONTAINER_HPP_

#include <vector>

namespace batya_script::utility {

template <typename T>
class IndexedContainer {
public:
	[[nodiscard]] virtual const T& get(size_t index) const = 0;

	[[nodiscard]] const T& operator[](size_t index) const;
};


template <typename T>
class MutableIndexedContainer : public IndexedContainer<T> {
	[[nodiscard]] virtual T& get(size_t index) = 0;

	[[nodiscard]] T& operator[](size_t index);
};


//////////////////////////////////////////////////////
//                  Implementation                  //
//////////////////////////////////////////////////////


template <typename T>
const T& IndexedContainer<T>::operator[](size_t index) const {
	return get(index);
}


template <typename T>
T& MutableIndexedContainer<T>::operator[](size_t index) {
	return get(index);
}

}
#endif //BATYA_SCRIPT_UTILITY_INDEXED_CONTAINER_HPP_
