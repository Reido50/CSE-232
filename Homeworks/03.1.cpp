/*  Reid Harry
    1/21/2020
    Write a program that reads in three floating point numbers, 
    it should output the minimum (smallest) value rounded to 2 decimal places.
*/

#include<iostream>
using std::cout; using std::cin; using std::fixed;

#include<iomanip>
using std::setprecision;

int main(){
    // Declare 3 floating point variables
    double num1, num2, num3;

    // Take in 3 numbers from user
    cin >> num1 >> num2 >> num3;

    // Change format of cout to fixed and 2 decimal places
    cout << fixed << setprecision(2);

    // Print smallest value
    if(num1 <= num2 && num1 <= num3){
        cout << num1;
    }else if(num2 <= num1 && num2 <= num3){
        cout << num2;
    }else if(num3 <= num1 && num3 <= num2){
        cout << num3;
    }
}