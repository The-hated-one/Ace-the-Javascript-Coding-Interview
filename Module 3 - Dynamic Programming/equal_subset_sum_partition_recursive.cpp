

/*
Problem Statement

Given a set of positive numbers, find if we can partition it into 
two subsets such that the sum of elements 
in both subsets is equal.
*/

#include<bits/stdc++.h>
using namespace std;

class PartitionSet {
 public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for(int ele : num) sum += ele;

    if(sum%2 != 0) return false;

    vector<vector<int>> dp(num.size(), vector<int>(sum/2+1, -1));
    return this->solve(num, dp, sum/2, 0);
  }

  private :
  bool solve(const vector<int>&num, vector<vector<int>> &dp, int sum, int currentIndex){
    if(sum == 0) return true;

    if(num.empty() || currentIndex >= num.size()) return false;

    if(dp[currentIndex][sum] == -1){
      if(num[currentIndex] <= sum){
        if(solve(num, dp, sum-num[currentIndex], currentIndex+1)){
          dp[currentIndex][sum] = 1;
          return true;
        }
      }

      dp[currentIndex][sum] = solve(num, dp, sum, currentIndex+1) ? 1 : 0;
    }

    return dp[currentIndex][sum] == 1 ? true : false;
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}
