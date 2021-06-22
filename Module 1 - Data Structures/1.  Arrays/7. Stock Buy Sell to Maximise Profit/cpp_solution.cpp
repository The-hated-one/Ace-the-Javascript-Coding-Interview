
/*
Description
Given a list of daily stock prices (integers for simplicity), return the buy and 
sell prices for making the maximum profit.

We need to maximize the single buy/sell profit. If we can’t make any profit, 
we’ll try to minimize the loss. 

INPUT 
[8, 5, 12, 9, 19, 1]
[21, 12, 11, 9, 6, 3]

OUTPUT
buy = 5, sell = 19
buy = 12, sell = 11
*/

#include<bits/stdc++.h>
using namespace std;

// SOLUTION
// Time Complexit : O(n)
// Space Complexity : O(1)
tuple<int, int> find_buy_sell_stock_prices(int* arr, int size){
	
	// base case
	if(arr == NULL || size < 2){
		tuple<int, int> result(make_pair(-1, -1));
  		return result;
	}
	
	int current_buy = arr[0];
	int current_sell = arr[1];
	int global_profit = current_sell - current_buy;
	
	int current_profit = INT_MIN;
	
	for(int i = 1; i < size; i++){
		
		current_profit = arr[i] - current_buy;
		
		if(current_profit > global_profit){
			global_profit = current_profit;
			current_sell = arr[i];
		}
		
		if(current_buy > arr[i]) current_buy = arr[i];
	}
	
	tuple<int, int> result(make_pair(
		current_sell-global_profit, // buy
		current_sell //sell
	));
	
	return result;	
}


int main() {
  int array[] = {1, 2, 3, 4, 3, 2, 1, 2, 5};
  tuple<int, int> result;
  result = find_buy_sell_stock_prices(array, 9);
  cout << "Buy Price: "<< get<0>(result) << ", Sell Price: " << get<1>(result) << endl;

  int array2[] = {8, 6, 5, 4, 3, 2, 1};
  result = find_buy_sell_stock_prices(array2, 7);
  cout << "Buy Price: " << get<0>(result) << ", Sell Price: " << get<1>(result) << endl;
}
