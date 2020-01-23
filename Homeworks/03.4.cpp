#include <iostream>
#include <iomanip>

int main() {
  int points_earned = 1000;
  std::cin >> points_earned;
  double final_grade = 4.0;
  if (points_earned >= 900) {
    final_grade = 4.0;
  } else if (points_earned >= 850) {
    final_grade = 3.5;
  } else if (points_earned >= 800) {
    final_grade = 3.0;
  } else if (points_earned >= 750) {
    final_grade = 2.5;
  } else if (points_earned >= 700) {
    final_grade = 2.0;
  } else if (points_earned >= 650) {
    final_grade = 1.5;
  } else if (points_earned >= 600) {
    final_grade = 1.0;
  } else{
    final_grade = 0;
  }
  
  std::cout << std::fixed << std::setprecision(1);
  std::cout << final_grade << std::endl;
}