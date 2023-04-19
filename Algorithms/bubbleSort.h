void bubbleSort(int arr[], int n){
    n--;
    int tmp{};
    
    // n iterations
    while(n>0){
        // 1 iteration
        for(int i = 0; i<n; i++){
            if(arr[i] > arr[i+1]){
                // Swap
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
        // Last number is sorted
        n--;
    }
}