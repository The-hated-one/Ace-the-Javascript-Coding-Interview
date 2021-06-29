using namespace std;

#include <iostream>
#include <limits>
#include <vector>

/*
Problem Statement 
Given an array of positive numbers and a positive number ‘S,’
find the length of the smallest contiguous subarray whose sum 
is greater than or equal to ‘S’. Return 0 if no such subarray exists.

Example 1:
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2

Example 2:
Input: [2, 1, 5, 2, 8], S=7 
Output: 1

Example 3:
Input: [3, 4, 1, 1, 6], S=8 
Output: 3
*/


class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    
    int si = 0;
    int len = 0;
    int sum = 0;
    int ans = -1;

    for(int i = 0; i < arr.size(); i++){
      sum = sum + arr[i];
      len++;

      if(sum >= S){
        if(ans == -1 || len < ans) ans = len;
        i = ++si;
        len = 0;
        sum = 0;
      }
    }
    if(ans!=-1) return ans;
    return 0;
  }
};

