

function binarySearchRotated(arr, start, end, key){
    if(start > end) return -1;

    while(start <= end){
        let mid = start + Math.floor((end-start)/2);

        if(arr[mid] === ele) return mid;

        // left part is sorted
        else if (arr[start] <= arr[mid] && key <= arr[mid] && key >= arr[start]) end = mid-1;

        // right part is sorted  
        else if (arr[mid] <= arr[end] && key >= arr[mid] && key <= arr[end]) start = mid+1;
          
        // right part is unsorted
        else if (arr[end] <= arr[mid]) start = mid + 1; 
          
        // left part is unsorted
        // else if (arr[start] >= arr[mid]) 
        else end = mid-1;
    }

    return -1;
}


let v1 = [6, 7, 1, 2, 3, 4, 5];
let eles = [7, 3, 4];

for(ele of eles){
    let ans = binarySearchRotated(v1, 0, v1.length-1, ele);
    console.log(`Element ${ele} found at location ${ans}`);
}