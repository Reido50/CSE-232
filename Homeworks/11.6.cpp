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
    istringstream stream;
    stream.str(s);

    string temp1, last, first, fin;

    while(getline(stream, temp1)){
        string temp2, temp3;
        istringstream small_stream;

        small_stream.str(temp1);
        while(small_stream >> temp2){
            temp3 += " " + temp2;
        }

        for(int i = temp3.length()-1; true; i--){
            if(temp3[i] == ' '){
                first = temp3.substr(1, i);
                last = temp3.substr(i+1);
                break;
            }
        }

        first.pop_back();

        fin += last + ", " + first + "\n";
    }

    return fin;
}

int main(){
    cout << LastnameFirstname("Reid Harry\n Luke Jerry\n Brett Hicks");
}