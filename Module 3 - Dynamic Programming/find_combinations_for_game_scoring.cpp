
/*
Description

Imagine a game where a player can score 1, 2 or 4 runs. 
Given a score, n, find the total number of ways to score n runs.
*/


// Scoring options are 1, 2, and 4
int scoring_options(int n) {
  int dp[n+1] = {0};
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 6;

  for(int i = 5; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-4];
  }
  return dp[n];
}
