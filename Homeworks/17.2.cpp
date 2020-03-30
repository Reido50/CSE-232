/*  Reid Harry
    3/30/2020
    Python lists have a handy feature where you can use negative indices to get at elements counting from the end of the list. 
    x[-1] returns the last element in x and x[-2] returns the penultimate element and so on. Implement a struct named "PythonicIntVector" 
    in the files "PythonicIntVector.h" and "PythonicIntVector.cpp" that supports the push_back and at methods of a vector of ints. 
    However, be sure to add the functionality of negative indices.

    Don't forget that the at method still should throw exceptions for invalid indices (just like in Python)!
*/

#include "17.2.h"

#include<vector>
using std::vector;
#include<stdexcept>
using std::logic_error;
#include<cstdlib>
using std::abs;

void PythonicIntVector::push_back(int x){
    list.push_back(x);
}

int PythonicIntVector::at(int x){
    if(x+1 > static_cast<int>(list.size())){
        throw logic_error("Index Out of Range");
    }else if(x < 0){
        if(abs(x) > static_cast<int>(list.size())){
            throw logic_error("Index Out of Range");
        }else{
            return (list[static_cast<int>(list.size()) + x]);
        }
    }else{
        return list[x];
    }
}