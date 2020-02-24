/*  Reid Harry
    2/24/2019
    Write a templated function named safe_divide that returns the result of division of its two 
    arguments. However, if the second argument (the demoninator) is zero, raise a std::runtime_error.
*/

#include<stdexcept>
using std::runtime_error;

template<typename T>
T safe_divide(T dividend, T divisor){
    if(divisor == 0){
        throw runtime_error("division by zero");
    }

    return dividend/divisor;
}