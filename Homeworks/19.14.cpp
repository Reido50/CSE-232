/*  Reid Harry
    4/12/2020
    Write a function (named "templated_array_copy") that takes two parameters (two arrays of the same type). It copies the 
    first array into the second. Note, it the arrays are different sizes, only copy what fits.
*/

#include<iostream>
#include<algorithm>
using std::copy; using std::min;

template<typename Type, size_t Size1, size_t Size2>
void templated_array_copy(Type (&ary1)[Size1], Type (&ary2)[Size2]){
    for(size_t i = 0; i < min(Size1, Size2); i++){
        ary2[i] = ary1[i];
    }
}