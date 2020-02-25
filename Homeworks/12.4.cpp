/*  Reid Harry
    2/25/2020
    Write a templated function, named "AllConvert", that takes a const reference to a string and a pointer to an int. 
    This function should convert the string to the templated type and return that. It should also adjust the int being 
    pointed to to indicate the number of characters of the string that were converted.

    You can assume that the string does not have any newline characters, and your function should ignore leading whitespace (like stoi does).
*/

#include<string>
using std::string;
#include<sstream>
using std::istringstream;
#include<iostream>
using std::cout;

template<typename T>
T AllConvert(const string & s, int * i){
    T var;
    istringstream iss(s), iss2;
    string temp = "";

    iss >> var;

    temp = (string)var;

    *i = temp.length();

    return var;
}

int main(){
    string s = "12";
    int pos = 99;

    cout << AllConvert<int>(s, &pos) << "\n";
    cout << pos;
}