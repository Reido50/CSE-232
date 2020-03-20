
#include <cassert>
#include <string>
using std::string;
#include <vector>
using std::vector; using std::inserter;
#include <utility>
using std::pair;
#include<algorithm>
using std::sort; using std::rotate; using std::find_if; using std::stable_partition;
#include<numeric>
using std::adjacent_difference; using std::plus;

int BinaryToInt(const string & s){

}

vector<int> Fibonacci(const int & i){
  vector<int> fib(i, 1);
  adjacent_difference(fib.begin(), fib.end()-1, fib.begin()+1, plus<int>());
  return fib;
}

void PassOrFail(vector<pair<string, int>> & v){
  sort(v.begin(), v.end());
  stable_partition(v.begin(), v.end(), 
                  [](const pair<string, int> & p){
                    return p.second >= 600;
                  });
}

void ShiftRange(vector<int> & v, int l, int r){
  sort(v.begin(), v.end());

  rotate(find_if(v.begin(), v.end(), 
                [l](const int & i){
                  return(i >= l);
                }), find_if(v.begin(), v.end(), 
                [r](const int & i){
                  return(i > r);
                }), v.end());
}

int main() {
  {
    // given (a vector of ints, and ints "left", and "right"), sort the vector, rotate all numbers in the range
    // [left,right] to end of vector
    std::vector<int> v = {13, 22, 4, 5, 3, 11, 16, 25, 7};
    ShiftRange(v, 10, 20);

    std::vector<int> w = {3, 4, 5, 7, 22, 25, 11, 13, 16};
    // Notice that 11, 13, 15 (the values between 10 and 20 are moved to the end)
    
    assert(v == w);
  }
  
  {
    // given a vector, where each element in the vector is a [name,grade] pair
    // sort range by name, partition range into pass and fail, preserving
    // alphabetic order within partition
    // Note: the grades are the number of points earned (600 points earns a passing grade)
    std::vector<std::pair<std::string, int>> v {
      {"josh", 851},
      {"mark", 600},
      {"charles", 412},
      {"sebnem", 1000},
      {"abdol", 905},
      {"imen", 300}
    };

    std::vector<std::pair<std::string, int>> w { 
      {"abdol", 905}, 
      {"josh", 851}, 
      {"mark", 600}, 
      {"sebnem", 1000}, // Everyone after this point failed
      {"charles", 412}, 
      {"imen", 300}
    };
    PassOrFail(v);
    assert(v == w);
  }
 
  
  {
    // generate 1st n fibonacci numbers
    // See: https://en.wikipedia.org/wiki/Fibonacci_number
    std::vector<int> v = {1, 1, 2, 3, 5, 8, 13, 21};
    auto w = Fibonacci(8);
    assert(v == w);
  }

  {
    // convert at string representing a binary number 
    // to an int
    const std::string binary_str = "10110";
    int result = BinaryToInt("10110");
    assert(result == 22);
  }
}

