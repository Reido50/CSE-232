/*  Reid Harry
    3/26/2020
    You're going to write a vector class called "FunnyVector", because it's kind of like a vector, but a funny one. For starters, 
    it can only contain numbers (ints, to be precise). Also, unlike std::vector, FunnyVector keeps all its ints in sorted order. Even 
    worse, when you call size() on it, it gives the sum of its elements, not the number of elements. And to top it all off, if you 
    put in numbers so that the sum goes over a threshold, all the numbers are erased. Fortunately, this threshold can be set when a 
    FunnyVector is created. And for the pruposes of testing, you can get() a std::vector<int> from a FunnyVector to see its contents.

    Provide the interface to your FunnyVector in funny_vector.hpp. You should write the implementation of FunnyVector in funny_vector.cpp
*/

#ifndef FUNNY_VECTOR_H
#define FUNNY_VECTOR_H

#include<vector>
using std::vector;

struct FunnyVector{
    vector<int> numbers;
    int threshold;
    int sum = 0;

    FunnyVector(int t):numbers(), threshold(t), sum(0){};

    void push_back(int x);
    vector<int> get();
    int size();
};

#endif