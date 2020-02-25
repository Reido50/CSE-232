/*  Reid Harry
    2/25/2020
    Write a void function called "OnlyUppercase" that has only two parameters, a reference to a istringstream 
    and a reference to an ostringstream. This function should read whitespace separated words from the first 
    argument and write those words (each with a trailing newline character) to the second argument. However, 
    only the words that are composed solely of UPPERCASE letters should be written to the second argument.
*/

#include<iostream>
using std::cout; using std::endl;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<string>
using std::string;

bool CheckUpper(string & s){
    for(auto chr: s){
        if(chr < 65 || chr > 90){
            return false;
        }
    }

    return true;
}

void OnlyUppercase(istringstream& in, ostringstream& out){
    string checkString;

    while(in >> checkString){

        if(CheckUpper(checkString)){
            out << checkString << "\n";
        }
    }
}