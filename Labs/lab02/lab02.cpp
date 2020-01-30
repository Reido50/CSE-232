#include<iostream>
using std::cin; using std::cout; using std::endl;

int main(){
    int count = 0;
    int sum = 0;
    int input;

    cin >> input;

    if(input < 0){
        cout << "Error";
    }else{
        while(input >= 10){
            while(true){
                if(input == 0){
                    break;
                }else{
                    sum += (input % 10);
                    input /= 10;
                }
            }
            input = sum;
            sum = 0;
            count++;
        }

        cout << count << " " << input;
    }
}