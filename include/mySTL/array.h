#ifndef MY_STL_ARRAY_H
#define MY_STL_ARRAY_H

#include<initializer_list>
#include<iostream>

template<typename T, size_t N>
class numeric_array {
    private:
        T* raw_array = new T[N];

    public:
        class iterator {
            private:
                T* curr;
            public:
                iterator(T* curr) : curr(curr) {};

                iterator& operator++(){
                    ++curr;
                    return *this;
                }

                iterator operator++(int){
                    auto copy = *this;
                    curr++;
                    return copy;
                }

                T& operator*(){
                    return *curr;
                }

                T operator[](int offset){
                    return *(curr + offset);
                }

                iterator operator+(int offset){
                    return iterator(curr + offset);
                }
    
                iterator operator-(int offset){
                    return iterator(curr - offset);
                }

                bool operator!=(const iterator& other){
                    return this->curr != other.curr;
                }

                bool operator==(const iterator& other){
                    return this->curr == other.curr;
                }

            
        };

        numeric_array(T e) {
            for(size_t i = 0; i < N; i++){
                raw_array[i] = e;
            }
        }
    
        numeric_array(std::initializer_list<T> init_list){
            size_t index = 0;
            for(auto ele:init_list){
                raw_array[index++] = ele;
            }
            while(index != N){
                raw_array[index++] = 0;
            }
        }

        iterator begin(){
            return iterator(raw_array);
        }

        iterator end(){
            return iterator(raw_array + N);
        }

        // TODO: Collapse to 16 elements with ellipses if list is too long
        void display_elements(int start=0, int end = N){
            std::cout<<"[";
            for(size_t i = start; i < end-1; i++){
                std::cout<<raw_array[i]<<", ";
            }
            std::cout<<raw_array[end-1]<<"]";
        }

        T& operator[](int index){
            return raw_array[index];
        }

        ~numeric_array(){
            delete[] raw_array;
        }


};

#endif

