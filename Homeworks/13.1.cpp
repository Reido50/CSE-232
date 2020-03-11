/*  Reid Harry
    3/11/2020
    Write a function, named "smallerThanPredecessor", that takes a reference to a vector of ints. 
    It should return an iterator pointing at the first element that is strictly smaller than the 
    element before it. You can assume that the vector has at least two elements. If no element 
    qualifies, return an iterator to one past the end of the vector.
*/

#include<vector>
using std::vector;
#include<iterator>
using std::iterator;

vector<int>::iterator smallerThanPredecessor(vector<int> & nums){
    for(auto ptr = nums.begin(); ptr != nums.end(); ++ptr){
        if(*ptr > *(ptr+1)){
            return (ptr+1);
        }
    }
}