

def binarySearchRotated(arr, start, end, key):
    if start >= end :
        return -1

    while start <= end :
         mid = start + (end-start)//2;

         if arr[mid] == ele :
             return mid
        
        elif arr[start] <= arr[mid] and key <= arr[mid] and key >= arr[start]:
            end = mid - 1
            
        elif arr[mid] <= arr[end] and key >= arr[mid] and key <= arr[end]: 
            start = mid + 1

        elif arr[end] <= arr[mid]:
            start = mid + 1

        elif arr[start] >= arr[mid]:
            end = mid - 1

    return -1



v1 = [6, 7, 1, 2, 3, 4, 5]
eles = [7, 1, 3, 4]

for ele in eles :
    print("Element {x} found at location {y}".format(x = ele, y = binarySearchRotated(v1, 0, len(v1)-1, ele)))
