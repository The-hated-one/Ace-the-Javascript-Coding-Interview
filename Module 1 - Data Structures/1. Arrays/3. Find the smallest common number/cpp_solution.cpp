
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v1 = {6, 7, 10, 25, 30, 63, 64};
  	vector<int> v2 = {1, 4, 5, 6, 7, 8, 50};
  	vector<int> v3 = {1, 6, 10, 14};
  	
  	int i, j, k;
  	i = j = k = 0;
  	
  	while(i < v1.size() && j < v2.size() && k < v3.size()){
  		// found the element
  		if(v1[i] == v2[j] && v2[j] == v3[k]){
  			cout<<v1[i];
  			break;
		  }
		  
		// i element of v1 is the smallest in the 3 arrays
		if(v1[i] <= v2[j] && v1[i] <= v3[k]) i++;
		
		// j element of v2 is the smallest in the 3 arrays
		else if(v2[j] <= v1[i] && v2[j] <= v3[k]) j++;
		
		// k element of v3 is the smallest in the 3 arrays
		// if(v3[k] <= v1[i] && v3[k] <= v2[j]) 
		else k++;
	  }
	  
	return 0;
}
