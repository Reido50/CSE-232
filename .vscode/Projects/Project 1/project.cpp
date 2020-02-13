/*  Reid Harry
    2/13/2020
    A program that can convert and do math in different bases.
    Input: Valid positive integers. Only bases 1-9. Will fit in an int.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<math.h>
using std::pow;

/*  convert_other_base_to_decimal
    this function takes a number and its base. It should return that same number in decimal. 
    Example: convert_other_base_to_decimal(104, 8) == 68    */
/*  Used this source to help loop through each digit of num
    https://stackoverflow.com/questions/8671845/iterating-through-digits-in-integer-in-c    */
int convert_other_base_to_decimal(int num, int base){
    int deci_num = 0;

    for(int i = 0; num < 0; i++){
        deci_num += pow(num % 10, i);
        num /= 10;
    }
    
    return deci_num;
}

/*  convert_decimal_to_other_base
    this function takes a decimal number and the desired base to convert it to. It should 
    return the number in that other base. 
    Example: convert_decimal_to_other_base(68, 8) == 104    */
/*  Used the algorithm from this source to help with converting decimals to other bases
    http://www.cs.trincoll.edu/~ram/cpsc110/inclass/conversions.html    */
int convert_decimal_to_other_base(int deci_num, int base){
    int num = 0;

    for(int i = 1; deci_num > 0; i *= 10){
        num += i * (deci_num % base);
        deci_num /= base;
    }

    return num;
}

/*  math_in_other_base
    this function takes two numbers, their base, and a character representing the mathematical
    operation to perform. It should return the result (in the specified base). The character
    can be one of + - * / %     */
int math_in_other_base(int num1, int num2, int base, char sign){
    if      (sign == '+'){
        
    }else if(sign == '-'){

    }else if(sign == '*'){

    }else if(sign == '/'){

    }else if(sign == '%'){

    }else{

    }
}

/*  main
    the main function should read from standard input the 4 parameters needed for the 
    math_in_other_base function and print the result of calling that function.  */
int main(){
    // get user input
    int num1, num2, base;
    char sign;
    cin >> num1 >> num2 >> base >> sign;

    cout << math_in_other_base(num1, num2, base, sign);
}