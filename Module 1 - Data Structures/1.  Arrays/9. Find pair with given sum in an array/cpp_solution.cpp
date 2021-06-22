#include<bits/stdc++.h>
using namespace std;

/*
Description

Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given 
value. Return true if the sum exists and return false if it does not.
*/

bool find_sum_of_two(vector<int>& arr, int val){
	unordered_map<int, int> mp;
	
	for(int i = 0; i < arr.size(); i++){
		if(mp[val - arr[i]] > 0){
			return true;
		}
		mp[arr[i]]++;
	}
	
	return false;
}

int main() {
  vector<int> v = {5, 7, 1, 2, 8, 4, 3};
  vector<int> test = {3, 20, 1, 2, 7};

  for(int i=0; i<test.size(); i++){
    bool output = find_sum_of_two(v, test[i]);
    cout << "find_sum_of_two(v, " << test[i] << ") = " << (output ? "true" : "false") << endl;
  }
  return 0;
}
