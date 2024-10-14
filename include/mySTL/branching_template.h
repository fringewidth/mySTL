#ifndef MYSTL_BRANCHING_TEMPLATE_H
#define MYSTL_BRANCHING_TEMPLATE_H
template <class T>
class branching_template : public data_template<T> {
    virtual const T& depth() const = 0;
    virtual branching_template<T>::iterator& root() const = 0;
    virtual ~branching_template() = default;

    class iterator : public data_template<T>::iterator {};
};

#endif