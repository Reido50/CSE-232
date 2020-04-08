/*  Reid Harry
    4/8/2020

    Write a class, named "TwoOrLess" with a header file (two_or_less.hpp) and an implementation file (two_or_less.cpp).

    This is a class that acts much like a set, except it can hold 0, 1, or 2 duplicates of an int. You need to support the insert, 
    count, and size methods with the same parameters and return types as the set<int> class (see test cases).
*/

#include "18.1.h"
// #include "two_or_less.hpp"
#include<vector>
using std::vector;
#include<set>
using std::set;
#include<utility>
using std::pair;
#include<algorithm>
using std::find;

TwoOrLess::TwoOrLess(){
    sets.push_back({});
    sets.push_back({});
}

pair<set<int>::iterator, bool> TwoOrLess::insert(const int& i){
    pair<set<int>::iterator, bool> result;

    if(sets[0].find(i) == sets[0].end()){
        result = sets[0].insert(i);
    }else{
        result = sets[1].insert(i);
    }

    return result;
}

size_t TwoOrLess::count(const int& i){
    size_t result = 0;
    if(sets[0].find(i) != sets[0].end()){
        result++;
    }
    if(sets[1].find(i) != sets[1].end()){
        result++;
    }
    return result;
}

size_t TwoOrLess::size(){
    return sets[0].size() + sets[1].size();
}