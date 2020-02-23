/*  Reid Harry
    2/10/2020
    Write a function (named "longest_letter_run") that takes two constant references to strings. 
    It shoud return an int. The first string is a piece of text, and the second string is the letters
    that we are looking for runs in. A run is a series of consecutive letters from the second string.

    Example:
    This call: longest_letter_run("this_is_some_text", "ais_")
    Should return a 7 because the longest letter run is "is_is_s".
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<iomanip>
#include<string>
using std::string;

int longest_letter_run(string s, string run){
    int length = 0;
    int temp_length = 0;
    bool found = false;

    s+=" ";

    for(auto chr1:s){
        for(int i = 0; i < run.length(); i++){
            if(chr1 == run[i]){
                temp_length++;
                found = true;
                break;
            }
            
            if(i == run.length() - 1){
                found = false;
                break;
            }
        }
        if(!found){
            if(temp_length > length){
                length = temp_length;
                temp_length = 0;
                found = true;
            }
        }
    }

    if(temp_length > length){
        length = temp_length;
        temp_length = 0;
        found = true;
    }

    return length;
}