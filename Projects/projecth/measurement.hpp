/*  Reid Harry
    4/17/2020
    You will be implementing a class, named "Measurement" that keeps track of values, error, and units for a measurement or calculation 
    involving the same. All of the material should be in a single implementation file named "project.cpp". The description of the functionality 
    you need to implement can be seen in the description for individual tests.
*/

#pragma once

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;

class Measurement{
    private:
        double value_;
        double uncertainty_;
        map<string,int> unit_;
    
    public:
        /*
        The constructor for the Measurement.
        Accepts 2 floating point values and a std::string.
        The parameters represent the value (of a measurement), the uncertainty (of the measurement), and the unit (e.g. meters or seconds).
        */
        Measurement(double v, double u, const string& unit);
        Measurement(double v, double u, const map<string,int>& unit);

        /*
        Makes Measurement compatable with printing.
        Two places after the decimal point and is in scientific notation with a trailing space character after the unit.
        */
        friend ostream& operator<<(ostream& out, const Measurement& m);

        /*
        Two measurements can be added or subtracted (if they have the same units). 
        If they have differing units, an std::invalid_argument exception is raised.
        */
        friend Measurement operator+(const Measurement& m1, const Measurement& m2);
        friend Measurement operator-(const Measurement& m1, const Measurement& m2);

        /*
        Two measurement can be multiplied, divided, and exponentiated reguardless of units.
        The new measurement's units are in alphabetical order and specific if they are raised to a power if needed when outputing to a stream.
        */
        friend Measurement operator*(const Measurement& m1, const Measurement& m2);
        friend Measurement operator/(const Measurement& m1, const Measurement& m2);
        friend Measurement operator^(const Measurement& m1, long n);
};