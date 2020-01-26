/*  Reid Harry
    1/26/2020
    Write a program that takes in two integers. It multiples the first number by the second, and prints the product on its own line. 
    Then multiples this product by the second number, repeating while the number is less than 10,000.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;

int main(){
    // take two ints at input
    int num1, num2;
    cin >> num1 >> num2;
    
    int product = num1 * num2;
    do{
        cout << product << endl;
        product *= num2;
    }while(product < 10000);
}