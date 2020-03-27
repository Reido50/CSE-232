/*  Reid Harry
    03/27/2020
    Implementation file for math_vector.h
*/

#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<math.h>
using std::pow;
#include<sstream>
using std::ostringstream;

#include "math_vector.h"

MathVector MathVector::add(const MathVector& v){
    x += v.x;
    y += v.y;

    return *this;
}

MathVector MathVector::mult(long num){
    x *= num;
    y *= num;

    return *this;
}

long MathVector::mult(const MathVector& v){
    return (x*v.x + y*v.y);
}

double MathVector::magnitude(){
    return pow(static_cast<double>(x*x + y*y), 0.5);
}

string vec_to_str(const MathVector& v){
    ostringstream oss;
    oss << v.x << ":" << v.y;
    
    return oss.str();
}