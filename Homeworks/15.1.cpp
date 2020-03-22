/*  Reid Harry
    3/22/2020
    You need to make a custom type called a "HousePrice". This type represents an address and its estimated Zillow price.
    It has two data members, a string with the house's address (named "address") and a double representing the price
    Zillow estimates for the house (named "price").

    Additionally, you need to write a function (not a member function, a regular one) that takes a const reference to a vector 
    of HousePrice and returns the average of the price in that vector as a double. This function is called "get_average_price".
*/

#include "15.1.h"

#include<string>
using std::string;
#include<vector>
using std::vector;

double get_average_price(const vector<HousePrice> & houses){
    double sum = 0;
    for(auto h : houses){
        sum += h.price;
    }
    return (sum/static_cast<int>(houses.size()));
}