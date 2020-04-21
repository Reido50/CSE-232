#include "redact.h"

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::any_of; using std::replace;

/*
    Takes a const ref string and returns a string that is the similar to the 
    argument string, but only has octothorpes ('#') instead of the original characters.
*/
string redact_all_chars(const string & s){
    string redacted(s.length(), '#');
    return redacted;
}

/*
    Takes a const ref string and returns a string that is the similar to the argument string, 
    but only has octothorpes ('#') instead of the original characters if those characters were 
    letters or digits (a-zA-Z0-9).
*/
string redact_alphabet_digits(const string & s){
    string redacted = "";
    for(auto chr: s){
        if((chr >= 48 && chr <= 57) || (chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122)){
            redacted += '#';
        }else{
            redacted += chr;
        }
    }
    return redacted;
}

/*
    Takes two arguments: a const ref string (input) and a const ref vector of strings (words_to_redact). 
    It returns a string that is the similar to the argument string, but only has octothorpes ('#') 
    instead of the original characters if those characters composed a word in words_to_redact. 
    Note, the matching string could be inside another word (univer###y).
*/
string redact_words(const string & input, const vector<string> & words_to_redact){
    string redacted = input;
    for(size_t i = 0; i < redacted.length(); i++){
        for(auto str: words_to_redact){
            if(redacted.substr(i, str.length()) == str){
                redacted.replace(i, str.length(), str.length(), '#');
                i += (str.length()-1);
            }
        }
    }
    return redacted;
}