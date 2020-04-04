/*  Reid Harry
    3/20/2020
    I'm interested in knowing if there are two adjacent strings in a list that are very similar to each other. For 
    instance, "Zach" and "Zack" are only one character apart.

    Write a function, named "CloseEnough" that takes a const reference to a vector of strings and an int. The vector 
    is a list of strings (each of the same length). The int represents how many characters can be different between 
    any two strings next to each other. This function should return the index (an int) of the string that is within the 
    second arguments distance to the next string in the vector. If no index fulfills this criteria, it should return -1.
*/

#include<string>
using std::string; using std::stoi;
#include<vector>
using std::vector;
#include<numeric>
using std::adjacent_difference;
#include<algorithm>
using std::find_if;

void comp(string& x, string& y, int& p, int& d){
    if(x[p] != y[p]){
        d++;
    }

    if(static_cast<int>(p) < static_cast<int>(x.length())){
        p++;
        comp(x, y, p, d);
    }
}

int HowClose(string& x, string& y){
    int diffs = 0;
    int pos = 1;

    comp(x, y, pos, diffs);

    return diffs;
}

int CloseEnough(const vector<string> & v, int i){
    vector<string> diffs(static_cast<int>(v.size()));

    adjacent_difference(v.begin(), v.end(), diffs.begin(), HowClose);

    return ((find_if(diffs.begin()+1, diffs.end(), 
                [i](string& x){
                    return (static_cast<int>(x[0]) >= i);
                }))) - (diffs.begin()+1);
}