/*  Reid Harry
    2/24/2020
    Write a function (named "LastnameFirstname") that takes a multiline string and returns a string with the names reformatted.

    The parameter will have names written "Firstname Lastname" one per line, but the returned string should have each name 
    written as "Lastname, Firstname". Note, the input string have have additional whitespace.
*/

#include<iostream>
using std::cout;
#include<string>
using std::string; using std::getline;
#include<sstream>
using std::istringstream; using std::ostringstream;

string LastnameFirstname(string s){
    istringstream stream, small_stream;
    stream.str(s);

    string temp1, temp2, temp3, last, first, final;

    while(getline(stream, temp1)){
        small_stream.str(temp1);
        temp1 = "";
        while(small_stream >> temp2){
            temp1 += temp2 + " ";
        }

        for(int i = temp2.length()-1; true; i--){
            if(temp2[i] == ' '){
                first = temp2.substr(0, i);
                last = temp2.substr(i+1);
                break;
            }
        }

        final += last + ", " + first + '\n';
    }

    return final;
}