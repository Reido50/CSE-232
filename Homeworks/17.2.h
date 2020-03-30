/*  Reid Harry
    3/30/2020
    Python lists have a handy feature where you can use negative indices to get at elements counting from the end of the list. 
    x[-1] returns the last element in x and x[-2] returns the penultimate element and so on. Implement a struct named "PythonicIntVector" 
    in the files "PythonicIntVector.h" and "PythonicIntVector.cpp" that supports the push_back and at methods of a vector of ints. 
    However, be sure to add the functionality of negative indices.

    Don't forget that the at method still should throw exceptions for invalid indices (just like in Python)!
*/

#ifndef PYTHON_VECTOR
#define PYTHON_VECTOR

#include<vector>
using std::vector;

struct PythonicIntVector{
    vector<int> list;

    void push_back(int x);
    int at(int x);
};

#endif