/*  Reid Harry
    2/6/2020
    Write a program that calculates pi using the Nilakantha Series. The program should accept a 
    threshold from standard in indicating how close to pi one should calculate. The program should 
    output for each term in the series: the result of the calculation of pi so far (fixed notation 
    and 6 significant figures) and the different between the aproximation and actual pi (scientific 
    notation and 2 significant figures). Once the difference is less than the threshold, cease 
    the program.
*/

#define _USE_MATH_DEFINES

#include<iostream>
using std::cin; using std::cout; using std::endl; using std::fixed; using std::scientific;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::pow; using std::abs;

int main(){
    double pi = 3;  // first item in the series is 3
    double threshold;
    double difference;

    cin >> threshold;   // user inputs the threshold

    for(int i = 0, j = 2; true; i++, j+=2){
        // find the difference between actual pi and calculated pi
        difference = abs(static_cast<double>(M_PI) - pi);

        // output calculated pi and difference
        cout << fixed << setprecision(6) << pi << " " << scientific << setprecision(2) << difference << endl;

        // break out of loop condition
        if(difference < threshold){
            break;
        }

        // perform the Nilakantha series calculation for one addition term
        pi += static_cast<double>((pow(-1.0,i))*(4.0))/static_cast<double>((j * (j+1) * (j+2)));
        
    }
}