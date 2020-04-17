/*  Reid Harry
    4/17/2020
    You will be implementing a class, named "Measurement" that keeps track of values, error, and units for a measurement or calculation 
    involving the same. All of the material should be in a single implementation file named "project.cpp". The description of the functionality 
    you need to implement can be seen in the description for individual tests.
*/

#include "measurement.hpp"

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<iomanip>
using std::scientific; using std::setprecision; using std::fixed;
#include<string>
using std::string;
#include<math.h>
using std::sqrt; using std::abs; using std::pow;
#include<exception>
using std::invalid_argument;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<sstream>
using std::ostringstream;

/*
Returns the added quadrature uncertainty of two uncertainty values.
uncertainty = sqrt(u1^2 + u2^2)
Used in adding and subtracting measurements
*/
double quadrature_uncertainty(double u1, double u2){
    return sqrt((u1*u1) + (u2*u2));
}

/*
Returns the added fractional quadrature uncertainty of two uncertainty values.
uncertainty = sqrt((u1/v1)^2 + (u2/v2)^2)
Used in adding and subtracting measurements
*/
double fractional_quadratur_uncertainty(double v1, double u1, double v2,  double u2){
    return sqrt((u1*u1)/(v1*v1) + (u2*u2)/(v2*v2));
}

/*
Returns a map of units as a string of alphabetically sorted units.
The key is the name of the unit and the value is the power of the unit
If the power is one, the unit will simply be added to the string without an exponent.
*/
string print_units(const map<string, int>& u){
    string result;
    ostringstream oss;
    for(pair<string, int> unit: u){
        if(unit.second == 1){
            oss << unit.first << " ";
        }else if(unit.second != 0){
            oss << unit.first << "^" << unit.second << " ";
        }
    }
    result = oss.str();
    return result;
}

/*
Returns a map of units that result from multiplying two units together
Adds the exponents
*/
map<string, int> multiply_units(const map<string, int>& u1, const map<string, int>& u2){
    map<string, int> new_unit = u1;
    for(pair<string, int> unit: u2){
        new_unit[unit.first] += unit.second; 
    }
    return new_unit;
}

/*
Returns a map of units that result from multiplying two units together
Subtracts the exponents
*/
map<string, int> divide_units(const map<string, int>& u1, const map<string, int>& u2){
    map<string, int> new_unit = u1;
    for(pair<string, int> unit: u2){
        new_unit[unit.first] -= unit.second; 
    }
    return new_unit;
}

/*
Returns a map of units that result from exponentiation
*/
map<string, int> pow_units(const map<string, int>& u1, long n){
    map<string, int> new_unit = u1;
    for(pair<string, int> unit: new_unit){
        new_unit[unit.first] *= n;
    }
    return new_unit;
}

Measurement::Measurement(double v, double u, const string& unit){
    value_ = v;
    uncertainty_ = u;
    unit_[unit] += 1;
}

Measurement::Measurement(double v, double u, const map<string,int>& unit){
    value_ = v;
    uncertainty_ = u;
    unit_ = unit;
}

ostream& operator<<(ostream& out, const Measurement& m){
    out << scientific << setprecision(2);
    out << m.value_ << " +- " << m.uncertainty_ << " " << print_units(m.unit_);
    out << fixed << setprecision(3);
    return out;
}

Measurement operator+(const Measurement& m1, const Measurement& m2){
    if(m1.unit_ == m2.unit_){
        Measurement result(m1.value_+m2.value_, quadrature_uncertainty(m1.uncertainty_, m2.uncertainty_), m1.unit_);
        return result;
    }else{
        throw invalid_argument("Units are not same");
    }
}

Measurement operator-(const Measurement& m1, const Measurement& m2){
    if(m1.unit_ == m2.unit_){
        Measurement result(m1.value_-m2.value_, quadrature_uncertainty(m1.uncertainty_, m2.uncertainty_), m1.unit_);
        return result;
    }else{
        throw invalid_argument("Units are not same");
    }
}

Measurement operator*(const Measurement& m1, const Measurement& m2){
    double new_val = m1.value_*m2.value_;
    Measurement result(new_val, abs(new_val) * fractional_quadratur_uncertainty(m1.value_, m1.uncertainty_, m2.value_, m2.uncertainty_), multiply_units(m1.unit_, m2.unit_));
    return result;
}

Measurement operator/(const Measurement& m1, const Measurement& m2){
    double new_val = m1.value_/m2.value_;
    Measurement result(new_val, abs(new_val) * fractional_quadratur_uncertainty(m1.value_, m1.uncertainty_, m2.value_, m2.uncertainty_), divide_units(m1.unit_, m2.unit_));
    return result;
}

Measurement operator^(const Measurement& m1, long n){
    if(n == 1){
        Measurement result(m1.value_, m1.uncertainty_, m1.unit_);
        return result;
    }else if(n == 0){
        Measurement result(1.0, 0.0, m1.unit_);
        return result;
    }else{
        double new_val = pow(m1.value_, n);
        Measurement result(new_val, abs(new_val)*(abs(n)*m1.uncertainty_/abs(m1.value_)), pow_units(m1.unit_, n));
        return result;
    }
}