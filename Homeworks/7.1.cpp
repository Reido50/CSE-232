/*  Reid Harry
    2/4/2020
    Write a program that reads a series of floating point numbers 
    from standard in and outputs each number with at most 4 significant 
    figures (in scientific notation).
*/

#include<iostream>
using std::cin; using std::cout; using std::scientific; using std::endl;
#include<iomanip>
using std::setprecision;

int main(){
    double input;

    cout << scientific << setprecision(3);

    while (cin >> input)
    {
        cout << input << endl;
    }
}