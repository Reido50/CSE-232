/*  Reid Harry
    2/26/2020
    Write a function named "Sum" that takes a vector of vector of int (as a const reference) and returns the sum of all the ints in that 2-d vector.
*/

#include<vector>
using std::vector;

int Sum(vector<vector<int>> & v_2d){
    int total = 0;
    for(auto i: v_2d){
        for(auto j: i){
            total += j;
        }
    }
    return total;
}