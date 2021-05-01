/*
Description 
You are given an array (list) of interval pairs as input where each interval has a start and end timestamp. 
The input array is sorted by starting timestamps. 
You are required to merge overlapping intervals and return a new output array.

Consider the input array below. 
Intervals (1, 5), (3, 7), (4, 6), (6, 8) are overlapping so they should be merged to 
one big interval (1, 8). Similarly, intervals (10, 12) and (12, 15) 
are also overlapping and should be merged to (10, 15).

INPUT
[(1, 5), (3, 7), (4, 6), (6, 8), (10, 12), (12, 15)]

OUTPUT
[(1,8), (10, 15)]

*/
#include<bits/stdc++.h>
using namespace std;

class Pair{
  public:
    int first, second;
    Pair(int x, int y){
      first = x;
      second = y; 
    }
};

// SOLUTION
// Time Complexity : O(n)
// Space Complexity : O(n)

vector<Pair> merge_intervals(vector<Pair>& v){
  
  if(v.size() == 0) return v;
  
  vector<Pair> result;
  result.push_back(v[0]);
  
  for(int i = 1; i < v.size(); i++){
  	int x1 = v[i].first;
  	int y1 = v[i].second;
  	int x2 = result[result.size()-1].first;
  	int y2 = result[result.size()-1].second;
  	
  	if(y2 >= x1) result[result.size()-1].second = max(y1, y2);
  	else result.push_back(v[i]);
  }
  
  return result; 
}

int main() {
  vector<Pair> v {
                  Pair(1, 5),
                  Pair(3, 7),
                  Pair(4, 6),
                  Pair(6, 8),
                  Pair(10, 12),
                  Pair(11, 15)
    };

  vector<Pair> result = merge_intervals(v);
  
  for(int i = 0; i < result.size(); i++){
    cout << "[" << result[i].first << ", " << result[i].second << "] ";
  }
}
