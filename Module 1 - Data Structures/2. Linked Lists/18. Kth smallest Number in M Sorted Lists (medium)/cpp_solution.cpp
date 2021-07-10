

using namespace std;

#include<bits/stdc++.h>

/*
Problem Statement
Given ‘M’ sorted arrays, find the K’th smallest number 
among all the arrays.
*/

class KthSmallestInMSortedArrays {
 public:
  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < lists.size(); i++){
      vector<int> curr = lists[i];
      for(int j = 0; j < curr.size(); j++) pq.push(curr[j]);
    }

    for(int i = 1; i < k; i++) pq.pop();

    return pq.top();
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}
