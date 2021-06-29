using namespace std;

#include<bits/stdc++.h>

//    TOP DOWN DP APPROACH
//    Time Complexity : O(N*S)
//    Space Complexity : O(N*S)

class PartitionSet {
public:
  int canPartition(const vector<int> &num) { 
    int sum = accumulate(num.begin(), num.end(), 0);

    vector<vector<int>>dp(num.size(), vector<int>(sum+1, -1));
    return helper(dp, num, 0, 0, 0);
  }

  private :
  int helper(vector<vector<int>>&dp, const vector<int>&num, int i, int sum1, int sum2){
    if(i == num.size()) return abs(sum1-sum2);

    if(dp[i][sum1] == -1){
      int ans1 = helper(dp, num, i+1, sum1+num[i], sum2);
      int ans2 = helper(dp, num, i+1, sum1, sum2+num[i]);

      dp[i][sum1] = min(ans1, ans2);
    }
    return dp[i][sum1];
  }
};


//   BRUTE FORCE APPROACH
//    Time Complexity : O(2^N)
//    Space Complexity : O(N)

class brutePartitionSet {
public:
  int canPartition(const vector<int> &num) { 
    return helper(num, 0, 0, 0);
  }

  private :
  int helper(const vector<int>&num, int i, int sum1, int sum2){
    if(i == num.size()) return abs(sum1-sum2);

    int ans1 = helper(num, i+1, sum1+num[i], sum2);
    int ans2 = helper(num, i+1, sum1, sum2+num[i]);
    
    return min(ans1, ans2);
  }
};

int main(int argc, char *argv[]) {
  cout<<"TOP DOWN DP APPROACH : "<<endl;
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
  
  cout<<"BRUTE FORCE APPROACH : "<<endl;
  brutePartitionSet bps;
  vector<int> num1 = {1, 2, 3, 9};
  cout << bps.canPartition(num1) << endl;
  num1 = vector<int>{1, 2, 7, 1, 5};
  cout << bps.canPartition(num1) << endl;
  num1 = vector<int>{1, 3, 100, 4};
  cout << bps.canPartition(num1) << endl;
  
  return 0;
}

