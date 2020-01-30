#include<iostream>
using std::cin; using std::cout;

int main(){
    int count = 0;  // additive persistance
    int sum = 0;    // used in summing up the digits
    int input;      // used to store user input and additive root

    // get user's interger input
    cin >> input;

    // finds additive persistance and additive root
    if(input < 0){  // negatives cannot be taken additive root of
        cout << "Error";
    }else{
        // continue while the number is in the double digits
        while(input >= 10){
            while(true){
                if(input == 0){     // if all the digits have been used
                    break;
                }else{
                    sum += (input % 10);    // add one of the digits
                    input /= 10;    // move to the next digits
                }
            }
            input = sum;    // put sum into input to loop through every digit
            sum = 0;    // reset sum
            count++;    // add to additive persistance
        }

        cout << count << " " << input;
    }
}