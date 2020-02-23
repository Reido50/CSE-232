/*  Reid Harry
    2/17/2020
    You will write a function (named "havel_hakimi") that given a degree sequence, will 
    determine whether or not it is graphical, in particular, an implementation of the 
    Havel-Hakimi algorithm. Your function will be as follows:

    It will accept a string with each character representing the degree of a different vertex, e.g. "1100" or "3211".

    It will output a boolean value of whether or not the degree sequence is graphical.
*/

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include<algorithm>
using std::sort;
#include<utility>
using std::reverse;

// used information from this source to develope descending_sort:
// https://stackoverflow.com/questions/39273339/sorting-string-in-descending-order
void descending_sort(string & s){
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
}

string decrement_sequence(string s){
    string new_s = "";
    int num;

    for(auto chr: s){
        num = static_cast<int>(chr);
        new_s += (--num);
    }

    return new_s;
}

int check_havel(string & s){
    bool all_zero = true;

    for(auto chr: s){
        if(chr == '\\'){
            return -1;
        }else if(chr != 0){
            all_zero = false;
        }
    }

    if(all_zero){
        return 0;
    }else{
        return 1;
    }
}

bool havel_hakimi(string s){
    descending_sort(s);

    int x = s[0] - 48;

    if(x >= s.length()){
        return false;
    }else{
        string decremented = decrement_sequence(s.substr(1, x));

        if(x < s.length()-1){
            s = decremented + s.substr(x + 1);
        }else{
            s = decremented;
        }
    }

    int result = check_havel(s);

    if(result == 0){
        return true;
    }else if(result == -1){
        return false;
    }else if(result == 1){
        return havel_hakimi(s);
    }
}