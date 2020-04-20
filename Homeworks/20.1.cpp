/*  Reid Harry
    4/20/2020
    Write a function, named "Compress", that takes an array of doubles and an int denoting the number of elements in that array. The function 
    should modify the array to no longer have elements that are within 1.0 of the preceding element. The function should return the remaining 
    number of elements (as an int).
*/

#include<algorithm>
using std::remove_if;
#include<math.h>
using std::abs;

int new_size;
int current;

int Compress(double list[], int size){
    new_size = size;
    current = 0;
    remove_if(list, list+size, 
              [list](double i){
                  if(i != list[0]){
                      if(abs(i-list[current-1]) < 1.0){
                          current++;
                          new_size--;
                          return true;
                      }else{
                          current++;
                          return false;
                      }
                  }else{
                    current++;
                    return false;
                  }
              });
    return new_size;
}