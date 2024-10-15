#ifndef MYSTL_ARRAY_H
#define MYSTL_ARRAY_H

#include <cstddef>
#include <type_traits>
#include<string>

template<class T, size_t N>
class array : public linear_template {
    private: 
        std::string T_name const = typeid(T).name();
        T* const arr;
        iterator front, back;

        void init();

    public:
        array();
        array(const T& e);

        ~array();

        T& first() const override;
        T& last() const override;
        iterator front() const override;
        iterator back() const override;

        iterator find(const T&) const override;

        void assert_out_of_bounds(const size_t index) const;

        void push(const T&) override = delete;
        T& pop() override = delete;
        void append(const T&) override = delete;
        void push_front(const T&) override = delete;


        class iterator : public linear_template<T>::iterator {
            private:
                size_t index;

            public:
                iterator(size_t i);

                iterator operator+(size_t) const override;
                iterator operator-(size_t) const override;
                iterator& operator++() override;
                iterator operator++(int) override;
                iterator& operator--() override;
                iterator operator--(int) override;
                T& operator*() const override;
                bool operator!=(iterator&) const override;
                
                T& operator[](array<T, N>, size_t) const;
        };

};

#endif