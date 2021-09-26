
/*
MaxSum Subsequence - Non Adjacent Elements

Find an efficient algorithm to find the maximum sum of a subsequence 
in an array so that no consecutive elements are part of this 
subsequence.
*/



int find_max_sum_nonadjacent(vector<int>& a) {
 
 if (a.size() == 0) {
    return 0;
  }

  if (a.size() == 1) {
    return a[0];
  }

  std::vector<int> result(a.size(), 0);

  result[0] = a[0];
  for (int i = 1; i < a.size(); i++)  {

    result[i] = max(a[i], result[i-1]);

    if ((i - 2) >= 0) {
      result[i] = max(result[i], a[i] + result[i-2]);
    }
  }
  return result[a.size() - 1];
}

int main() {
  vector<int> v = {1, -1, 6, -4, 2, 2};
  int sum = find_max_sum_nonadjacent(v);
  cout << "Max sum of nonadjacent subsequence: " << sum;
}
