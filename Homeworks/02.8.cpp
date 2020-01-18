// Reid Harry
// 1/18/2020
// Simple IO
#include <iostream>
using std::cout;
using std::cin;

int main() {
  int number = -1;

  cin >> number;
  
  if((number % 2) < 1){
    cout << "Even";
  }else{
    cout << "Odd";
  }
    
}