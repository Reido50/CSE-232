/*  Reid Harry
    3/22/2020
    You need to make a custom type called a "HousePrice". This type represents an address and its estimated Zillow price.
    It has two data members, a string with the house's address (named "address") and a double representing the price
    Zillow estimates for the house (named "price").

    Additionally, you need to write a function (not a member function, a regular one) that takes a const reference to a vector 
    of HousePrice and returns the average of the price in that vector as a double. This function is called "get_average_price".
*/

#ifndef ZILLOW
#define ZILLOW

#include<string>
using std::string;

struct HousePrice{
    string address;
    double price;
};

#endif