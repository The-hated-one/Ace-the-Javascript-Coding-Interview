
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr = {1, 10, 20, 0, 59, 63, 0, 88, 0};
	
	int r, w; // r = read_index, w = write_index
	r = w = arr.size()-1;
	
	while(r >= 0){
		if(arr[r] != 0){
			arr[w] = arr[r];
			w--;
		}
		r--;
	}
	
	while(w >= 0){
		arr[w] = 0;
		w--;
	}
	
	for(int ele : arr) cout<<ele<<" ";
	
	return 0;
}
