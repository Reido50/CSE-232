// Reid Harry
// 1/18/2019
// Age from birthday and date
#include<iostream>
using std::cout; using std::cin; using std::endl;

int main(){
  // year, month, day for birthdate
  int birth_year, birth_month, birth_day;
  cin >> birth_year >> birth_month >> birth_day;

  // year, month, day for current date
  int current_year, current_month, current_day;
  cin >> current_year >> current_month >> current_day;
  
  int age;
  
  if((current_month > birth_month) 
     || ((current_month == birth_month) && (current_day >= birth_day))){
    cout << "They have had birthday this year.";
    age = current_year - birth_year;
  }else{
    cout << "They haven't had birthday this year.";
    age = --current_year - birth_year;
  }
  
  cout << endl << "Their age is " << age << "." << endl;
}