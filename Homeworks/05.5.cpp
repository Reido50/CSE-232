/*  Reid Harry
    1/30/2020
    For a series of whitespace delimited integers (note, the running average should be rounded 
    to the hundredth place. However, if a non-positive number is encounted, the average should 
    be reset and a newline character emitted. Otherwise, the running averages should be separated 
    by a space.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl; using std::noskipws; using std::fixed;
#include<iomanip>
using std::setprecision;

int main(){
    int input = 0;
    double total = 0.0; // Running sum of all numbers inputted
    int i = 0;  // Counter

    cout << fixed << setprecision(2);   // Output formatting

    // Reads in user inputed integers and outputs a running average
    while(cin >> input){
        if(input <= 0){ // Non-Positive case
            i = 0;
            total = 0;
            cout << endl;
        }else{          // Positive case
            ++i;
            total += input;
            cout << (total/i) << " ";
        }
    }
}