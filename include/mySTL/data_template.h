#ifndef MYSTL_DATA_TEMPLATE_H
#define MYSTL_DATA_TEMPLATE_H
#include <cstddef>

template <class T>
class data_template {
    private:
        size_t size = 0;
    public:
        virtual size_t get_size() const;
        virtual const bool is_empty() const;
        virtual const bool contains(const T&) const = 0;
        virtual data_template<T>::iterator find(const T&) const = 0;
        virtual const T& get_min() const = 0;
        virtual const T& get_max() const = 0;

        virtual void insert(const T&);
        virtual void remove(const T&);   
        virtual void clear();

        virtual ~data_template() = default;

        class iterator {
            public:
                virtual iterator operator+(size_t) const = 0;
                virtual iterator operator-(size_t) const = 0;
                virtual iterator& operator++() = 0;
                virtual iterator operator++(int) = 0;
                virtual iterator& operator--() = 0;
                virtual iterator operator--(int) = 0;
                virtual T& operator*() const = 0;
                virtual bool operator!=(iterator&) const = 0;
        };

        using it = iterator;
};
#endif