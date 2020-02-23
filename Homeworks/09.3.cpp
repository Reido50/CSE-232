/*  Reid Harry
    2/12/2020
    Write a program that reads from standard in three things: a word to find, a word 
    to replace with, and single line of text to perform the find-replace on.

    The program should output the three things, as well as, the line after performing the find and replace.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<limits>

int main(){
    // get input
    string find, replace, line, oldLine;
    cin >> find;
    cin >> replace;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, line);
    oldLine = line;

    // find and replace
    int findPos = 0;
    while(true){
        findPos = line.find(find, findPos);
        if(findPos == string::npos){
            break;
        }
        line.erase(findPos, find.length());
        line.insert(findPos, replace);
        findPos += replace.length();
    }

    // print results
    cout << "Find Word: \"" << find << "\"" << endl <<
            "Replace Word: \"" << replace << "\"" << endl <<
            "Pre Line: \"" << oldLine << "\"" << endl <<
            "Post Line: \"" << line << "\"" << endl;

}