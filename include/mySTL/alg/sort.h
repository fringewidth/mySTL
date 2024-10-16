#ifndef MYSTL_SORT_H
#define MYSTL_SORT_H

#include "../array.h"
#include "swap.h"
#include<iostream>

template<class rand_iterator>
void quick_sort(rand_iterator begin, rand_iterator end){
    if(begin == end || begin + 1 == end){
        return;
    }
    rand_iterator i = begin;
    rand_iterator j = begin + 1;
    rand_iterator p = begin;
    while(j != end){
        if(*j < *p){
            ++i;
            swap(*i, *j);
        }
        ++j;
    }
    swap(*p, *i);
    quick_sort(begin, i);
    quick_sort(i + 1, end);
}

#endif