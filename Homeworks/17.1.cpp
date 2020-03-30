/*  Reid Harry
    3/30/2020
    Write a struct named "SafePtrToDouble" that is used to provide a (slightly) safer way to work with pointers 
    (you'll learn better solutions in CSE 335). One major problem with pointers is that they can be dereferenced 
    even when they are nullptr (meaning they have an invalid address to dereference). A nullptr value for a pointer 
    is used to indicate that the pointer isn't pointing at a valid memory location. But it is up to the programmer 
    to confirm that a pointer is not nullptr before dereferencing it. But programmers make mistakes!

    This struct should accept as a converting constructor a pointer to a double. This struct must define two methods 
    that both have no parameters:

    "Dereference": this method should act like a dereference of the pointer the struct was created with. However, if 
    the pointer is nullptr then a std::logic_error should be thrown
    "Value": this method should return the value of the pointer.
*/

#include "17.1.h"

#include<stdexcept>
using std::logic_error;

double& SafePtrToDouble::Dereference(){
    if(ptr){
        return *ptr;
    }else{
        throw logic_error("Null Ptr Error");
    }
}

double* SafePtrToDouble::Value(){
    return ptr;
}