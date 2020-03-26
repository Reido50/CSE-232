/*  Reid Harry
    3/26/2020
    You should make a struct (named "Thermostat") in the files "thermostat.h" and "thermostat.cpp". It should support 4 constructors:

    1. A default constructor that has a high setting of 30C, a low setting of 15C, and a hysteresis value of 2C.
    2. There should be a 2-parameter constructor that accepts a high and low setting, and has a hysteresis value of 2C.
    3. A 3-parameter constructor that accepts all three settings.
    4. And lastly, a explicit std::string constructor that accepts a string formatted like: "High=30C, Low=15C, Hysteresis=2C".

    You also need to define a function named "ThermostatToString" that takes a Thermostat object and returns a string in the same form as 
    the string construction accepts.

    Lastly, (and most importantly) you need to have a member function named "GetStateAfterReading" that accepts a temperature and returns 
    the state of the thermostat ("Heating", "Cooling", or "Off"). Note: all temperatures in this problem are ints.
*/

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include<string>
using std::string;

struct Thermostat{
    string status = "Off";
    int high = 30;
    int low = 15;
    int hysteresis = 2;

    Thermostat() = default;
    Thermostat(int h, int l): status("Off"), high(h), low(l), hysteresis(2){};
    Thermostat(int h, int l, int x): status("Off"), high(h), low(l), hysteresis(x){};
    explicit Thermostat(string s);

    string GetStateAfterReading(int t);
};


#endif
