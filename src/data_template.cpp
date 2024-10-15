#include<mySTL/data_template.h>
#include <cstddef>

template<class T>
size_t data_template<T>::get_size() const{
    return size;
}

template<class T>
const bool data_template<T>::is_empty() const {
            return size == 0;
}

template<class T>
void data_template<T>::insert(const T& e){
    size++;
}

template<class T>
void data_template<T>::remove(const T& e){
    size--;
}

template<class T>
void data_template<T>::clear(){
    size = 0;
}