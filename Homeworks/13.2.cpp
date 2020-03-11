/*  Reid Harry
    3/11/2020
    Write a function, named sortByCourseNumber, that takes a reference to a vector of string 
    (like {"CSE 232", "ECE 100", "CSE 450", "CSE 232"}) and returns nothing. The function should 
    reorder the vector so that the courses are sorted by number in ascending order. You can assume 
    that the department code is separated from the number by a space and that all course numbers 
    are 3 characters long.
*/

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::sort;

bool isCourseNumberSmaller(string x, string y){
    x = x.substr(x.length()-3);
    y = y.substr(y.length()-3);

    return(stoi(x) < stoi(y));
}

void sortByCourseNumber(vector<string> & courses){
    sort(courses.begin(), courses.end(), isCourseNumberSmaller);
}