/*  Reid Harry
    1/30/2020
    Write a program that reads in characters from standard input and outputs 
    the number of times it sees an 'a' followed by the letter 'b'.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl; using std::noskipws;

int main(){
    int counter = 0;
    char current = 'x';
    char prev = 'x';    // Holds the previous character read in by cin
    
    // Make cin also read whitespace
    cin >> noskipws;

    // Get user input of chars using a while loop
    while(cin >> current){
        // If an "ab" is detected
        if(current == 'b' && prev == 'a'){
            counter++;
        }

        prev = current;
    }

    // Output how many "ab" sequences were found.
    cout << counter;
}