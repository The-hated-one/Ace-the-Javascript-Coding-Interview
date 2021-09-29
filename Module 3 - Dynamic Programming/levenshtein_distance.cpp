

/*
Description

Given two strings, compute the Levenshtein distance between them, 
meaning the minimum number of edits required to convert 
one string to the other.

The Levenshtein distance, LD is a measure of the difference between 
two strings, s1 and s2. It is the minimum number of deletions, 
insertions, or substitutions required to transform s1 into s2
It is also known as the edit distance.
*/


#include<bits/stdc++.h>

int solve(string s1, string s2, int**output){
  int m = s1.size();
  int n = s2.size();

  if(m == 0 || n == 0) return max(m, n);

  if(output[m][n] != -1) return output[m][n];

  int ans;

  if(s1[0] == s2[0]) ans = solve(s1.substr(1), s2.substr(1), output);
  else{
    int x = solve(s1.substr(1), s2, output) + 1;
    int y = solve(s1, s2.substr(1), output) + 1;
    int z = solve(s1.substr(1), s2.substr(1), output) + 1;

    ans = min(x, min(y, z));
  }

  output[m][n] = ans;

  return ans;
}

int levenshtein_distance(string str1, string str2){
  int m = str1.size();
  int n = str2.size();

  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n];
    for(int j = 0; j <= n; j++) output[i][j] = -1;
  }

  return solve(str1, str2, output);
}
