
/*
# Problem Statement
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. 
Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:
Input: [4, 0, 3, 1]
Output: 2

Example 2:
Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7

*/

#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

int findMissingNumber(vector<int> &nums){
	
	for(int i = 0; i < nums.size(); ){
		if(nums[i] < nums.size() && nums[i] != nums[nums[i]]) swap(nums, i, nums[i]);
		else i++;
	}
	
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != i) return i;
	}
	
	return nums.size();
}

int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << findMissingNumber(v1) << endl;
}
