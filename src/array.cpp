#include "mySTL/array.h"
#include <cstddef>
#include <type_traits>

template<class T, size_t N>
array<T, N>::array() {
    init();
    static_assert(std::is_trivially_constructible<T>::value, T_name + "is not trivially constructible/")
    arr = new T[N]();
}

template<class T, size_t N>
array<T, N>::array(const T& e) {
    init();
    std::string constexpr constructor_error_string = "Single brace initialization only possible if constructor " + T_name + "(" + T_name + ") or " + T_name + "(" + T_name + "&) is defined."
    static_assert(std::is_constructible<T, T>::value, constructor_error_string);
    arr = new T[N] {e};
}

template<class T, size_t N>
array<T, N>::~array() {
    delete[] arr;
}

template<class T, size_t N>
void array<T, N>::assert_out_of_bounds(size_t index) const {
    assert(index >= 0 && index < N, "Index out of bounds");
}


template<class T, size_t N>
T& array<T, N>::first() const {
    return arr[0];
}

template<class T, size_t N>
T& array<T, N>::last() const {
    return arr[N-1];
}

template<class T, size_t N>
void array<T, N>::init(){
    static_assert(N > 0, "Array size must be greater than 0.");
    size = N;
    front = iterator(0);
    back = iterator(N-1);
}

template<class T, size_t N>
array<T, N>::iterator::iterator(size_t i=0) : index(i) {};

template<class T, size_t N>
array<T, N>::iterator array<T, N>::iterator::operator+(size_t n) const {
    assert_out_of_bounds(index + n);
    return iterator(index + n);
}

template<class T, size_t N>
array<T, N>::iterator array<T, N>::iterator::operator-(size_t n) const {
    assert_out_of_bounds(index - n);
    return iterator(index - n);
}

template<class T, size_t N>
array<T, N>::iterator& array<T, N>::iterator::operator++() {
    assert_out_of_bounds(index + 1);
    ++index;
    return *this;
}

template<class T, size_t N>
typename array<T, N>::iterator array<T, N>::iterator::operator++(int) {
    assert_out_of_bounds(index + 1);
    auto copy = *this;
    index++;
    return copy; 
}

template<class T, size_t N>
array<T, N>::iterator& array<T, N>::iterator::operator--() {
    assert_out_of_bounds(index - 1);
    --index;
    return *this;
}

template<class T, size_t N>
typename array<T, N>::iterator array<T, N>::iterator::operator--(int) {
    assert_out_of_bounds(index - 1);
    auto copy = *this;
    index--;
    return copy;
}

template<class T, size_t N>
T& array<T, N>::iterator::operator*() const {
    return array[index];
}

template <class T, size_t N>
bool array<T, N>::iterator::operator!=(iterator &) const {
    return index != it.index;
}