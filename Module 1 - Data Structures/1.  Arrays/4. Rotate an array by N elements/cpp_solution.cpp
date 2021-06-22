
#include<bits/stdc++.h>
using namespace std;

/*
Description
Given an array of integers, rotate the array by N 
elements where N is an integer:

For positive values of NN, perform a right rotation.
For negative values of NN, perform a left rotation.
Make sure you make changes to the original array.
*/

void rotate_left(vector<int> &arr){
    int temp = arr[0];
    int n = arr.size();
    for(int i = 1; i < n; i++) arr[i-1] = arr[i];
    arr[n-1] = temp;
}

void rotate_right(vector<int> &arr){
    int n = arr.size();
    int temp = arr[n-1];
    for(int i = n-2; i>=0; i--) arr[i+1] = arr[i];
    arr[0] = temp;
}

void rotate_array(vector<int>& arr, int n) {
 if( n > 0){
     for(int i = 0; i < n; i++) rotate_right(arr);
 }else if(n < 0){
     n = n*-1;
     for(int i = 0; i < n; i++) rotate_left(arr);
 }
}

int main() {
  vector<int> arr = {1, 10, 20, 0, 59, 86, 32, 11, 9, 40};

  cout<<"Array Before Rotation"<<endl;
  for(int i = 0; i < arr.size(); i++)
    cout<<std::to_string(arr[i])+", ";
  cout<<endl;
  
  cout<<"Array After Rotation"<<endl;
  
  rotate_array(arr, 2);
  
  for(int x = 0; x < arr.size(); x++)
    cout<<std::to_string(arr[x])+", ";
  cout<<endl;
  return 0;
}
