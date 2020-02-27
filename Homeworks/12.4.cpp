/*  Reid Harry
    2/25/2020
    Write a templated function, named "AllConvert", that takes a const reference to a string and a pointer to an int. 
    This function should convert the string to the templated type and return that. It should also adjust the int being 
    pointed to to indicate the number of characters of the string that were converted.

    You can assume that the string does not have any newline characters, and your function should ignore leading whitespace (like stoi does).
*/

#include<string>
using std::string; using std::to_string;
#include<sstream>
using std::istringstream;
#include<iostream>
using std::cout;

template<typename T>
T AllConvert(const string & s, int * i){
    istringstream iss(s), iss2(s);
    char remaining;
    int count = 0;
    T value;

    iss >> value;

    while(iss.get(remaining)){
        count++;
    }

    *i = s.length() - count;

    return value;
}

int main(){
    string s = "12";
    int pos = 99;

    cout << AllConvert<int>(s, &pos) << "\n";
    cout << pos;
}