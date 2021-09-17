
/*
Description 
The Fibonacci numbers form a sequence, known as the Fibonacci sequence 
where each number is the sum of two preceding ones, starting from 0
 and 1.

The Fibonacci numbers are defined as:

F(0) = 0
F(1)= 1
F(n)= F(n-1) + F(n-2)

By using the defintion above, the first 10 Fibonacci 
numbers are: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

Write a code to find the nth Fibonacci number in the 
Fibonacci sequence.
*/

int get_fibonacci(int n) {
  //TODO: Write - Your - Code
  int dp[n+1] = {0};
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}
