// Sequential Search (and variation)

// Returns true or false
// Input is an array of integers
// Target value is int
bool seqSearch(int array[], int length, int target){
    // Do search
    // 1. Start at zero
    int index = 0;
    // 4. Check if index < length
    while(index<length){
        // 2. Check if value at index is target
        if(array[index] == target){
            // 3b. We found it
            return true;
        }
        else{
            // 3a. We did not find it
            index++;
        }
    }
    // We searched everything and didn't find it
    return false;
}

bool seqSearchR(int array[], int length, int target){
    // Base Case
    // If length is zero
    if(length==0)
        return false;
    // Check if the first value is the target
    else if(array[0]==target){
        return true;
    }
    // Check the rest
    // Recursive case
    else{
        return seqSearchR(++array, --length, target);
    }
}