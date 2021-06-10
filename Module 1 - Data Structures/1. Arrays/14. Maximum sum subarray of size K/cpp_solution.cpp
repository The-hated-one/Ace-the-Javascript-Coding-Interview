
/*
# Problem Statement
Given an array of positive numbers and a positive number ‘k,’ 
find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:
Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:
Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1)

int findMaxSumSubArray(int k, const vector<int>& arr){
	int ans = 0;
	for(int i = 0; i < k; i++) ans += arr[i];
	
	for(int i = k; i<arr.size(); i++){
		ans = max(ans, ans + arr[i] - arr[i-k]);
	}
	
	return ans-1;
}

int main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
