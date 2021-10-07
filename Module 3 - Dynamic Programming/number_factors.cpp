
/*
Problem Statement

Given a number ‘n’, implement a method to count how many 
possible ways there are to express ‘n’ as the sum of 1, 3, or 4.
*/

using namespace std;

#include <iostream>

class ExpressNumber {

public:
  int CountWays(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(n == 3) return 2;
    if(n == 4) return 4;

    int dp[n+1]{0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;

    for(int i = 5; i <= n; i++) dp[i] = dp[i-1] + dp[i-3] + dp[i-4];

    return dp[n];

  }
};

int main(int argc, char *argv[]) {
  ExpressNumber *en = new ExpressNumber();
  cout << en->CountWays(4) << endl;
  cout << en->CountWays(5) << endl;
  cout << en->CountWays(6) << endl;

  delete en;
}
