
/*
Problem Statement
Find the maximum value in a given Bitonic array. 
An array is considered bitonic if it is monotonically increasing 
and then monotonically decreasing. Monotonically increasing or 
decreasing means that for any index i in the array arr[i] != arr[i+1].
*/


using namespace std;

#include<bits/stdc++.h>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    int i = 0;
    int n = arr.size();
    for( ;i < n-1; i++){
      if(arr[i] > arr[i+1]) return arr[i];
    }
    if(i == n-1) return arr[i];
  }

};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}

