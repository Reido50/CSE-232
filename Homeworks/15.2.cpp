/*  Reid Harry
    3/22/2020
    Write a struct that has only two data members, a string named "password" and another string named "secret". This struct is 
    called "SecretKeeper". The purpose of this type is too only share its secret with users that know the password. The struct 
    isn't too secure yet, but we'll learn more ways to control information later in the course.

    The SecretKeeper type also has a function member named "get_secret" that takes a single argument, a string that represents 
    a user providing a password. If the user's password matches the struct's password, return the secret, otherwise, return a empty string.
*/

#include "15.2.h"

#include<string>
using std::string;

string SecretKeeper::get_secret(string guess){
    if(guess == password){
        return secret;
    }else{
        return string();
    }
}