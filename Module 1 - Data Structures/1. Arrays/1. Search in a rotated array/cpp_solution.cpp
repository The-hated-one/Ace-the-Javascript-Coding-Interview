
#include<bits/stdc++.h>
using namespace std;

int binarySearchRotated(vector<int> arr, int ele){
	int start = 0;
	int end = arr.size()-1;
	
	while(start <= end){
		int mid = start + (end-start)/2;
		
		// found the element
		if(arr[mid] == ele) return mid;
		
		// ele is smaller than arr[mid] and greater than arr[start]
		if(arr[mid] >= arr[start] && ele >= arr[start] && ele <= arr[mid]) end = mid-1;
		
		// ele is smaller than arr[end] and greater than arr[mid]
		else if(arr[mid] <= arr[end] && ele >= arr[mid] && ele <= arr[end]) start = mid+1;
		
		// left part is unsorted
		else if(arr[mid] <= arr[start]) end = mid-1;
		
		// right part is unsorted
		// arr[mid] >= arr[end]
		else start = mid + 1;
	}
}


int main(){
	vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
	vector<int> eles = {7, 2, 4};
	
	for(int ele : eles){
		cout<<"Element "<<ele<<" found at location "<<binarySearchRotated(v1, ele)<<endl;
	}
	
	return 0;
}
