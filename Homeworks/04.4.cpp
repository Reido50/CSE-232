/*  Reid Harry
    1/26/2020
    Write a program that can output the largest value and sum for a series of lines. 
    The first line of input consist of two integers: the number of lines and the number
    of values on each line. Then the rest of the input will consist of floating point 
    values (in the number of lines and number of values per line previously indicated). 
    Be sure your formatting matches the test cases (round to the nearest hundredths).
*/

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;
#include<limits>
using std::numeric_limits;

int main(){
    // formatting
    cout << fixed << setprecision(2);

    // get input of lines and numbers to compare
    int lines, nums;
    cin >> lines >> nums;

    for(int i = 0; i < lines; i++){
        double max = 0;
        double sum = 0;
        for(int j = 0; j < nums; j++){
            // get input of one of the numbers
            double num;
            cin >> num;

            // Find max
            if(j == 0){
                max = num;
            }else if(num > max)
            {
                max = num;
            }
            
            // Add num to running sum
            sum += num;
        }
        cout << "Line " << i << ": Max = " << max << "; Sum = " << sum << endl;
    }
}