#ifndef MYSTL_LINEAR_TEMPLATE_H
#define MYSTL_LINEAR_TEMPLATE_H
template <class T>
class linear_template : public data_template<T> {
    public:
        virtual T& first() const = 0;
        virtual T& last() const = 0;
        virtual linear_template<T>::iterator front() const = 0;
        virtual linear_template<T>::iterator back() const = 0;
          
        virtual void push(const T&) = 0;
        virtual T& pop() = 0;
        virtual void append(const T&) = 0;
        virtual void push_front(const T&) = 0;

        virtual ~linear_template() = default;

        class iterator : public data_template<T>::iterator {};
};

#endif