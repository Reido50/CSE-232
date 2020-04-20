/*  Reid Harry
    4/20/2020
    Write a function, named "ArrayAdd" that takes two arrays (and their sizes) and returns a new array (really a pointer) to an array 
    with the elements of the first array followed by the second. The parameters are a dynamically allocated int array (followed by an 
    int denoting its size) and a second dynamically allocated int array (again, followed by its size). Be sure to delete the argument 
    arrays when you are done adding them.
*/

#include<algorithm>
using std::copy;

int* ArrayAdd(int a1[], int s1, int a2[], int s2){
    int new_size = s1 + s2;
    int * new_array = new int[new_size];
    copy(a1, a1+s1, new_array);
    copy(a2, a2+s2, new_array+s1);
    delete [] a1;
    delete [] a2;
    return new_array;
}