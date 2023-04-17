// Binary search for an integer in an array
bool binarySearch(int arr[], int length, int target){
    int center = length/2;
    while(length>0){
        int mid = arr[center];
        if(mid==target){
            return true;
        }
        else if(mid>target){
            length /=2;
            center = length/2;
        }
        else{
            // Increment the array pointer to go 1 index past the center
            arr += center + 1;
            // Since we skipped center+1 values, the length should be that much less
            length -= center + 1;
            center = length/2;
        }
    }
    return false;
}

bool binarySearchR(int arr[], int length, int target){
    if(length==0)
        return false;
    else if(arr[length/2+1]==target)
        return true;
    else if(arr[length/2+1]>target)
        return binarySearchR(arr, length/2, target);
    else
        return binarySearchR(arr+length/2+1, length/2-1, target);
}