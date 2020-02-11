/*  Reid Harry
    2/10/2020
    Write a function, called "letter_swap" that takes a const reference to a string 
    as its only parameter and returns a string. For every letter (A-Za-z) in the string, 
    replace it with its "opposite" in the alphabet. For instance, 'a' is replaced with 
    'z' and 'Y' is replaced with 'B'. All other characters should be left unchanged.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;

char find_opposite(int a){
    if(a >= (int)'a' && a <= (int)'m'){
        return (char)((int)'z' - (a - (int)'a'));
    }else if(a >= (int)'n' && a <= (int)'z'){
        return (char)((int)'a' + ((int)'z' - a));
    }else if(a >= (int)'A' && a <= (int)'M'){
        return (char)((int)'Z' - (a - (int)'A'));
    }else if(a >= (int)'N' && a <= (int)'Z'){
        return (char)((int)'A' + ((int)'Z' - a));
    }else{
        return (char)a;
    }
}

string letter_swap(string s){
    string swapped = "";
    int ascii;

    for(auto chr:s){
        ascii = (int)chr;
        
        swapped += find_opposite(ascii);
    }

    return swapped;
}