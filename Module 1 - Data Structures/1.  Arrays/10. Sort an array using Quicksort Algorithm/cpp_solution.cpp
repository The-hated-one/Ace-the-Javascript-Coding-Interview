
/*
Description
Given an integer array, sort it in ascending order using the quicksort algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

// SOLUTION
// Time Complexity : O(nlogn)
// Space Complexity : O(logn)

int partition(int arr[], int start, int end){
	
	// choose pivot
	int pivot = arr[start];
	
	// count elements smaller than pivot
	int count = 0;
	for(int i = start+1; i <= end; i++){
		if(pivot >= arr[i]) count++;
	}
	
	// swap the pivot
	int pi = start + count;
	int temp = arr[start];
	arr[start] = arr[pi];
	arr[pi] = temp;
	
	// ensure left half is smaller than the pivot and
	// right part is larger than the pivot
	
	int i = start, j = end;
	while(i<=pi && j>= pi){
		while(arr[i] <= pivot) i++;
		while(arr[j] > pivot) j--;
		if(i < pi && j > pi){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	
	return pi;	
}


void quick_sort_rec(int arr[], int start, int end){
	if(start >= end) return;
	
	int pi = partition(arr, start, end);
	quick_sort_rec(arr, start, pi-1);
	quick_sort_rec(arr, pi+1, end);
}


void quick_sort(int arr[], int size){
	quick_sort_rec(arr, 0, size-1);
}

int main()
{
  int a[] = {55, 23, 26, 2, 18, 78, 23, 8, 2, 3};
    
  cout << "Before Sorting" << endl;
  for (int i : a) {
    cout << i << ", ";
  }
  cout << endl;
  
  quick_sort(a, sizeof(a)/sizeof(int));
  
  cout << endl << "After Sorting" << endl;
  for (int i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
