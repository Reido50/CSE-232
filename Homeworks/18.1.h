/*  Reid Harry
    4/8/2020

    Write a class, named "TwoOrLess" with a header file (two_or_less.hpp) and an implementation file (two_or_less.cpp).

    This is a class that acts much like a set, except it can hold 0, 1, or 2 duplicates of an int. You need to support the insert, 
    count, and size methods with the same parameters and return types as the set<int> class (see test cases).
*/

#ifndef TWO_OR_LESS
#define TWO_OR_LESS

#include<vector>
using std::vector;
#include<set>
using std::set;
#include<utility>
using std::pair;

class TwoOrLess{
    private:
        vector<set<int>> sets;

    public:
        TwoOrLess();
        pair<set<int>::iterator, bool> insert(const int& i);
        size_t count(const int& i);
        size_t size();
};

#endif