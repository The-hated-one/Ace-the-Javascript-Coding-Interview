
/*
Problem Statement

Any number will be called a happy number if, after repeatedly 
replacing it with a number equal to the sum of the square of 
all of its digits, leads us to number ‘1’. 
All other (not-happy) numbers will never reach ‘1’. Instead, they 
will be stuck in a cycle of numbers which does not include ‘1’.
*/


using namespace std;

#include <iostream>

class HappyNumber {
 public:

  static int findSquare(int num){
    int ans = 0;

    while(num > 0){
      ans = ans + (num%10)*(num%10);
      num = num/10;
    }
    
    return ans;
  }

  static bool find(int num) {
    int slow = num;
    int fast = num;

  do{
      slow = findSquare(slow);
      fast = findSquare(findSquare(fast));
  }while(fast != slow);

    if(slow == 1) return true;
    return false;
  }
};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
