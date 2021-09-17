
/*
Description

Given an array, find the contiguous subarray with the largest sum.
*/


int find_max_sum_sub_array(int arr[], int n) {
  int currentSum = arr[0], max_so_far = arr[0];

  for(int i = 1; i < n; i++){
    // currentSum += arr[i];
    if(currentSum < 0) currentSum = arr[i];
    else currentSum += arr[i];
    
    max_so_far = max(max_so_far, currentSum);
  }

  return max_so_far;
}
