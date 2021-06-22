
/*
Problem Statement

Given a sorted array, create a new array containing squares of all the numbers 
of the input array in the sorted order.

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]
*/

#include<bits/stdc++.h>
using namespace std;

// SOLUTION
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> makeSquares(const vector<int> &arr){
	int start = 0, end = arr.size()-1;
	vector<int> ans;
	
	while(start <= end){
		int x = arr[start]*arr[start];
		int y = arr[end]*arr[end];
		
		if(x >= y){
			ans.push_back(x);
			start++;
		}else{
			ans.push_back(y);
			end--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char* argv[]) {
  vector<int> result = makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
