#include "include/mySTL/array.h"
#include<iostream>

using namespace std;

int main () {
    array<int, 5> arr;
    arr[4] = 541;
    cout<<*(arr.get_back())<<endl;
}