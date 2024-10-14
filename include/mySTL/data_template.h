#ifndef MYSTL_DATA_TEMPLATE_H
#define MYSTL_DATA_TEMPLATE_H
template <class T>
class data_template {
    public:
        virtual size_t get_size() const = 0;
        virtual const bool is_empty() const = 0;
        virtual const bool contains(const T&) const = 0;
        virtual data_template<T>::iterator& find(const T&) const = 0;
        virtual const T& get_min() const = 0;
        virtual const T& get_max() const = 0;

        virtual void insert(const T&) = 0;
        virtual void remove(const T&) = 0;        
        virtual void clear() = 0;

        virtual ~data_template() = default;

        class iterator {
            virtual iterator& operator+(size_t) const = 0;
            virtual iterator& operator-(size_t) const = 0;
            virtual iterator& operator++() = 0;
            virtual iterator& operator--() = 0;
            virtual T& operator*() const = 0;
            virtual bool operator!=(iterator&) const = 0;
        };

        using it = iterator;
};
#endif