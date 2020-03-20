/*  Reid Harry
    3/11/2020
    Write a function, named onlyNumbers, that takes a const reference to a string and returns a 
    string composed only of the characters from the original string that are digits.
    No looping!!!
*/

#include<algorithm>
using std::copy_if;
#include<string>
using std::string;

string onlyNumbers(const string & str){
    string copy = "";
    copy_if(str.begin(), str.end(), back_inserter(copy), isdigit);
    return copy;
}