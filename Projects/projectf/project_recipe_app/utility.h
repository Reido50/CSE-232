#pragma once

#include<iostream>
using std::endl; using std::cout;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
#include<ios>
using std::ostream; using std::streamsize;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<limits>
using std::numeric_limits;
#include<algorithm>
using std::find_if;
#include<exception>
using std::invalid_argument;
#include<numeric>
using std::gcd;

pair<int, int> SimplifyFraction(int n, int d){
    int factor = gcd(n,d);
    return make_pair(n/factor, d/factor);
}

// Take a numerator and denominator and return a string that is formatted for output of a reduced mixed number if appropriate
string FormatNumber(int n, int d){
    ostringstream oss;

    if(d == 1 || n%d==0){
        oss << n/d;
        }else if(n < d){
        oss << n << "/" << d;
    }else{
        oss << n/d << "-" << n%d << "/" << d;
    }
    
    return oss.str();
}

// Takes a string and returns a version of that string without leading or trailing whitespace
string RemoveWhitespace(const string& line){
        size_t first_not, last_not;
        // Find first non-whitespace in "line"
        first_not = line.find_first_not_of(" \t");
        if(first_not == string::npos){
            first_not = 0;
        }
        // Find last non-whitespace in "line"
        last_not = line.find_last_not_of(" \t");
        if(last_not == string::npos){
            last_not = line.length();
        }
        return line.substr(first_not, last_not - (first_not-1));
}

/*
    Takes a reference to an istringstream containing either a whole number, fraction, mixed number, or improper fraction.
    Returns a pair containing numerator and denominator of an improper fraction representing the value
*/
pair<int,int> MakeImproper(const string& s){
    int whole, numerator, denominator;
    char check_next;
    pair<int, int> result;
    istringstream iss(s);
    iss >> numerator;
    check_next = iss.get();
    if(check_next == '/'){
        // Fraction case
        iss >> denominator;
        result = SimplifyFraction(numerator, denominator);
    }else if(check_next == '-'){
        // Mixed number case
        whole = numerator;
        iss >> numerator;
        iss.get();
        iss >> denominator;
        result = SimplifyFraction(whole*denominator+numerator, denominator);
    }else{
        // Standard integer case
        result.first = numerator;
        result.second = 1;
    }
    return result;
}

pair<pair<int, int>,pair<string, string>> StringToIngredient(const string& i){
    string quantity, unit, name;
    istringstream iss(RemoveWhitespace(i));

    getline(iss, quantity, ' ');
    while(iss.get() == ' '){
    }
    iss.unget();
    getline(iss, unit, ' ');
    while(iss.get() == ' '){
    }
    iss.unget();
    getline(iss, name);
    while(iss.get() == ' '){
    }
    iss.unget();

    return make_pair(MakeImproper(RemoveWhitespace(quantity)),make_pair(RemoveWhitespace(unit), RemoveWhitespace(name)));
}