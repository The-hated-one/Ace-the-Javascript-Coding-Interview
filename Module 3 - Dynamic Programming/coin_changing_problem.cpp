
/*
Coin Changing Problem

Given coin denominations and the total amount, 
find the number of ways to make the change.
*/

int solve_coin_change(vector<int>& denominations, int amount){
  int dp[500] = {0};
  dp[0] = 1;

  for(int i = 0; i < denominations.size(); i++){
    for(int j = denominations[i]; j <= amount; j++){
      dp[j] = dp[j] + dp[j-denominations[i]];
    }
  }

  return dp[amount];
}
