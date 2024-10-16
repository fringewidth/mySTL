#ifndef MYSTL_SWAP_H

#define MYSTL_SWAP_H

template<class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif