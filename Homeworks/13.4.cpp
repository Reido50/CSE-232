/*  Reid Harry
    3/11/2020
    Write a function, named seriesOfLetters, that takes a reference to a vector of chars and returns nothing. 
    The function should modify the vector to contain a series of letters increasing from the smallest letter 
    (by ASCII value) in the vector. Note, the vector should not change in size, and the initial contents of the 
    vector (excepting the smallest letter) do not matter.
*/

#include<vector>
using std::vector;
#include<algorithm>
using std::sort;
#include<numeric>
using std::iota;

void seriesOfLetters(vector<char> & chars){
    sort(chars.begin(), chars.end());
    iota(chars.begin(), chars.end(), chars[0]);
}