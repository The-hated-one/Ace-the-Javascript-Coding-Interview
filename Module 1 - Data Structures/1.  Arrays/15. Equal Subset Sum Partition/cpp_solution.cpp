
/*
Problem Statement #
Given a set of positive numbers, find if we can partition it into two subsets 
such that the sum of elements in both the subsets is equal.

Example 1:
Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}

Example 2: 
Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 3, 4} & {1, 7}

Example 3: 
Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into two subsets with equal sum.

*/

#include<bits/stdc++.h>
using namespace std;

//Solution - Brute Force 0/1 Knapsack
// Time Complexity : O(2^N)
// Space Complexity : O(N)

bool canPartition_bf(const vector<int> &num, int sum, int currentIndex){
	if(sum == 0) return true;
	
	if(num.empty() || currentIndex >= num.size()) return false;
	
	if(num[currentIndex] <= sum){
		if(canPartition_bf(num, sum-num[currentIndex], currentIndex+1)) return true;
	}
	
	return canPartition_bf(num, sum, currentIndex+1);
}

bool canPartition_2(const vector<int> &num){
	int sum = 0;
	for(int ele : num) sum += ele;
	
	if(sum%2 != 0) return false;
	
	return canPartition_bf(num, sum/2, 0);
}

// -----------------------------------------------------------------------------------------------------

//Solution - Top Down DP with Memoization
// Time Complexity : O(N*S)
// Space Complexity : O(N*S)

bool canPartition_dp(vector<vector<int>> &dp, const vector<int> &num, int sum,int currentIndex){
	if(sum == 0) return true;
	
	if(num.empty() || currentIndex >= num.size()) return false;
	
	if(dp[currentIndex][sum] == -1){
		if(num[currentIndex] <= sum){
			if(canPartition_dp(dp, num, sum-num[currentIndex], currentIndex+1)){
				dp[currentIndex][sum] = 1;
				return true;
			}
		}
		
		dp[currentIndex][sum] = canPartition_dp(dp, num, sum, currentIndex+1) ? 1 : 0;
	}
	
	return dp[currentIndex][sum] == 1 ? true : false;
}

bool canPartition_1(const vector<int> &num){
	int sum = 0;
	for(int ele : num) sum += ele;
	
	if(sum%2 != 0) return false;
	
	vector<vector<int>>dp(num.size(), vector<int>(sum/2+1, -1));
	return canPartition_dp(dp, num, sum/2, 0);
}

int main(int argc, char *argv[]) {
  cout << "Brute force 0/1 knapsack"<<endl;
  vector<int> num = {1, 2, 3, 4};
  cout << canPartition_2(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << canPartition_2(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << canPartition_2(num) << endl;
	
  cout << "Top Down DP approach"<<endl;
  vector<int> num1 = {1, 2, 3, 4};
  cout << canPartition_1(num1) << endl;
  num1 = vector<int>{1, 1, 3, 4, 7};
  cout << canPartition_1(num1) << endl;
  num1 = vector<int>{2, 3, 4, 6};
  cout << canPartition_1(num1) << endl;
}

