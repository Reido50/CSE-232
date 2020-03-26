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

#include "16.1.h"

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<stdexcept>
using std::invalid_argument;

Thermostat::Thermostat(string s){
    vector<int> v;
    istringstream iss(s);
    string item;
    while(getline(iss, item, '=')){
        try{
            v.push_back(stoi((item)));
        }catch (invalid_argument& e){}
    }
    status = "Off";
    high = v[0];
    low = v[1];
    hysteresis = v[2];
}

string Thermostat::GetStateAfterReading(int t){
    if(status == "Off"){
        if(t > high + hysteresis){
            status = "Cooling";
        }else if(t < low - hysteresis){
            status = "Heating";
        }
    }else if(status == "Cooling"){
        if(t < low - hysteresis){
            status = "Heating";
        }else if(t < high - hysteresis){
            status = "Off";
        }
    }else if(status == "Heating"){
        if(t > high + hysteresis){
            status = "Cooling";
        }else if(t > low + hysteresis){
            status = "Off";
        }
    }

    return status;
}

string ThermostatToString(Thermostat t){
    ostringstream oss;
    oss << "High=" << t.high << "C, Low=" << t.low << "C, Hysteresis=" << t.hysteresis << "C";
    return oss.str();
}