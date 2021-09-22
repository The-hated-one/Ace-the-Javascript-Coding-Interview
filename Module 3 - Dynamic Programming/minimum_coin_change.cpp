
/*
Introduction

Given an infinite supply of ‘n’ coin denominations and a 
total money amount, we are asked to find the minimum number 
of coins needed to make up that amount.
*/s

#include <bits/stdc++.h>
using namespace std;

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    // TODO: Write your code here
    if(total == 0) return 0;

    int dp[100] = {0};

    for(int i = 1; i <= total; i++){
      dp[i] = INT_MAX;

      for(int j = 0; j < denominations.size(); j++){
        if(i-denominations[j] >= 0){
          int subprob = dp[i-denominations[j]];
          dp[i] = min(dp[i], subprob+1);
        }
      }
    }
    return dp[total];
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
}
