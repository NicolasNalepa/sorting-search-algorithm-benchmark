#include "algorithms.h"

/*
Purpose: Sorts an array of floats in an ascending order using the 
         selection sort algorithm
Parameters: 
    arr[] - array of floats to be sorted 
    size - number of elements in the array 
Example: 
    input: [3.2, 1.5, 4.8]
    output: [1.5, 3.2, 4.8]
Effect: 
    Modifies the original array by sorting it in place
Return:
    None. 
*/

void selectionSort(float arr[], int size) { 
    int i, j, minIndex;
    float temp; 

    //outer loop which moves the boundry of the unsorted portion
    for (i = 0; i < size -1; i++) {

        //assume the current is the smallest
        minIndex = i;

        // inner loop: finds the actual smallest element 
        for (j = i + 1; j < size; j++) {
            if ( arr[j] < arr[minIndex]) {
                minIndex = j; // updates the index of the smallest index 
            }
        }

        //swap the found min with the first unsorted element 
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

/*
Purpose: 
    sorts an array of floats in ascending order using the insertion sort algorithm
Parameters:
    arr[] - array of floats to be sorted 
    size - number of elements in the array 
Example: 
    Input:  [3.2, 1.5, 4.8]
    Output: [1.5, 3.2, 4.8]
Effect: 
    Modifies the original array by sorting it in place.
Return:
    None. 
*/

void insertionSort(float arr[], int size) {     
    int i, j;
    float key;

// start from the second element 
for (i = 1; i < size; i++) {

    key = arr[i];
    j = i-1;

    //shift elements to the right and make space for the key
    while (j>= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    //insert key into correct position
    arr[j+1] = key;

    }
}

/*
Pupose: 
    sorts an array of floats in ascending order using the bubble sort algorithm 
Parameters: 
    arr[] - array of floats to be sorted
    size  - number of elements in the array
Example:
    Input:  [3.2, 1.5, 4.8]
    Output: [1.5, 3.2, 4.8]
Effect:
    Modifies the original array by sorting it in place.
Return:
    None.
*/

void bubbleSort(float arr[], int size) {
    int i, j;
    float temp;

    //outer loop: controls the number of passes
    for(i = 0; i < size - 1; i++) {

        //inner loop: compare adjacent elements 
        for (j = 0; j < size - i - 1; j++) {

            //swap if elements are in the wrong order
            if (arr[j] > arr[j + 1]){
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

/*
Purpose: merge two sorted halves of an array into one sorted 
         section.
Parameters:
    arr[] - array containing the subarrays
    left  - starting index
    mid   - middle index
    right - ending index
Example: 
    Input:  left=[1.5, 3.2], right=[2.1, 4.8]
    Output: [1.5, 2.1, 3.2, 4.8]
Effect:
    Combines two sorted halves into one sorted section
Return:
    None. 
*/

void merge(float arr[], int left, int mid, int right) { 
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    float leftArr[n1];
    float rightArr[n2];

    //copy data into temp array
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    
    for (j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];

    }

    i = 0;
    j = 0;
    k = left;

    //merge the temp array back into arr[]
    while ( i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;

        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;

    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/*
Purpose: 
    Recursively divides and sorts subarrays for merge sort
Parameters: 
    arr[] - array to sort
    size  - number of elements
Example:
     Input:  [3.2, 1.5, 4.8]
     Output: [1.5, 3.2, 4.8] 
Effect: 
    sorts the array using divide and conquer 
Return 
    None.
*/

void mergeSortHelper(float arr[], int left, int right) { 

//base case 
if (left >= right)
    return;

int mid = (left + right) / 2;

// recursivley sort the left side 
mergeSortHelper(arr, left, mid);

// recursivley sort the right half 
mergeSortHelper(arr, mid + 1, right);

merge(arr, left, mid, right);

    }

/*
Purpose:
    Sorts an array using the merge sort algorithm. 
Parameters:
    arr[] - array to sort
    size  - number of elements
Example:
    Input:  [3.2, 1.5, 4.8]
    Output: [1.5, 3.2, 4.8]
Effect:
    Sorts the array in place using divide and conquer. 
Return:
    None.
*/
void mergeSort(float arr[], int size) {
    mergeSortHelper(arr, 0, size - 1);
}

/*
Purpose:
    partitions the array around a pivot so that the smaller 
    elements are placed to the left and larger elements are placed 
    to the right 
Parameters:
    arr[] - array of floats
    left  - starting index of the subarray
    right - ending index of the subarray
Example:
    If the pivot is 4.0 than values smaller than that move left and larger
    values move right 
Effect:
    rearranges elements in the subarray
Return;
    the final index of the pivot
*/

int partition(float arr[], int left, int right) {
    float pivot = arr[right];
    float temp;
    int i = left - 1;
    int j;

    // move all the smaller elements before the pivot 
    for (j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //implement pivot in its correct sorted position 
    temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;

}

/*
Purpose: 
    Recursivly sorts a subarray using Quick sort 
Parameters:
    arr[] - array of floats
    left  - starting index of the subarray
    right - ending index of the subarray
Example:
    Input:  [3.2, 1.5, 4.8, 2.1], left=0, right=3
    Output: [1.5, 2.1, 3.2, 4.8]
Effect:
    Modifies the array by sorting the specified subarray 
Return:
    None.
*/

void quickSortHelper(float arr[], int left, int right) { 
    int pivotIndex;

    //Base case
    if (left >= right) {
        return;
    }

    //partition the array and get the pivot position 
    pivotIndex = partition(arr, left, right);

    //sort left  side of pivot recursivly
    quickSortHelper(arr, left, pivotIndex - 1);

    //sort right side of pivot 
    quickSortHelper(arr, pivotIndex + 1, right);

}

/*
Purpose: Sorts an array of floats in ascending order using the quick 
         sort algorithm.
Paramters: 
    arr[] - array of floats to be sorted
    size  - number of elements in the array
Example:
    Input:  [3.2, 1.5, 4.8]
    Output: [1.5, 3.2, 4.8]
Effect:
    Modifies the original array by sorting it in place 
Return:
    None.
*/

void quickSort(float arr[], int size) {
    quickSortHelper(arr, 0, size - 1);
}

/*
Purpose:
    sorts a subarray of floats in ascending order using the selection
    sort algorithm and only sort between indices start and end 
Parameters:
    arr[]  - array of floats to be sorted
    start  - starting index of the range to sort
    end    - ending index of the range to sort
    size   - number of elements in the array
Example:
    Input:  [3.2, 1.5, 4.8, 2.1, 6.0], start=1, end=3
    Output: [3.2, 1.5, 2.1, 4.8, 6.0]
Effect:
        Modifies the array in place, only sorting the specified range
Return:
    None.
*/

void selectionSortRange(float arr[], int start, int end, int size) {
    int i, j, minIndex;
    float temp;

    for (i = start; i < end; i++) {

        minIndex = i;

        for (j = i + 1; j<= end; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    
    }

}

/*
Purpsoe:
    sorts an array of floats in ascendinf order using the isnertion sort 
    algorithm only starting from the given startIndex
Parameters: 
    arr[]      - array of floats to be sorted
    size       - number of elements in the array
    startIndex - index to begin sorting from
Example:
    Input:  [3.2, 1.5, 4.8, 2.1, 6.0], startIndex=2
    Output: [3.2, 1.5, 2.1, 4.8, 6.0]
Effect:
    Modifies the array in place, only sorting from startIndex onward
Return:
    None.
*/

void insertionSortFrom(float arr[], int size, int startIndex) {
    int i, j;
    float key;

    for (i = startIndex; i < size; i++) {
        
        key = arr[i];
        j = i - 1;

        while (j >= startIndex && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
    
        arr[j + 1] = key;
    
    }

}

/*
Purpose:    
    sorts the first front elements and the last rear elements of the array using 
    bubble sort which leaves the middle portion unchanged 
Paramters:
    arr[]  - array of floats to be sorted
    front  - number of elements to sort from the beginning
    rear   - number of elements to sort from the end
    size   - number of elements in the array
Example:
    Input:  [5.0, 3.0, 1.0, 9.0, 8.0, 7.0], front=2, rear=2
    Output: [3.0, 5.0, 1.0, 9.0, 7.0, 8.0]
Effect:
        Modifies the array in place, only sorting the front and rear portions
Return:
    None.
*/

void bubbleSortFrontAndRear(float arr[], int front, int rear, int size) {
    int i, j;
    float temp;

    // sort the first 'front' elements
    for (i = 0; i < front - 1; i++) {
        for (j = 0; j < front - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

   //sort the last 'rear' elements
    for (i = 0; i < rear - 1; i++) {
        for (j = size - rear; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
Purpose:
    sorts only the first half of an array using merge sort algorithm 
Parameters:
    arr[] - array to sort
    left  - starting index
    right - ending index
Example:
    Input:  [5.0, 3.0, 1.0, 9.0, 8.0, 7.0]
    Output: [1.0, 3.0, 5.0, 9.0, 8.0, 7.0]
Effect:
    modifies the first half of the array in place, leaving the second half unchanged
Return:
    None.
*/

void mergeSortFirstHalf(float arr[], int size) {
    
    if (size <= 1) return;
    mergeSortHelper(arr, 0, (size / 2) - 1);
}

/*
Purpose:
    sorts an array of floats using a hybrid merge sort algorithm.
    if the subarray size is below the THRESHOLD then insertion sort will be used
    instead of continuing to divide 
Parameters:
    arr[]  - array of floats to be sorted
    left   - starting index of the subarray
    right  - ending index of the subarray
Example:
    Input:  [3.2, 1.5, 4.8, 2.1, 6.0]
    Output: [1.5, 2.1, 3.2, 4.8, 6.0]
Effect:
    Modifies the array in place using a hybrid sorting strategy
Return:
    None.
*/

void hybridMergeSort(float arr[], int left, int right) {

    // if subarray is smaller than threshod and use insertion sort 
    if (right - left + 1 <= THRESHOLD) {
       
        int i, j;
        float key;
        
        for (i = left + 1; i <= right; i++) {
            
            key = arr[i];
            j = i - 1;

            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;

        }

        return;

    }

    int mid = (left + right) / 2;

    hybridMergeSort(arr, left, mid);
    hybridMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);

}

/*
Purpose:
    Recursively sorts a subarray using quick sort, using the middle
    element as the pivot instead of the last element.
Parameters:
    arr[]  - array of floats to be sorted
    left   - starting index of the subarray
    right  - ending index of the subarray
Example:
    Input:  [3.2, 1.5, 4.8, 2.1, 6.0]
    Output: [1.5, 2.1, 3.2, 4.8, 6.0]
Effect:
    Modifies the array in place by sorting the specified subarray
Return:
    None.
*/

void quickSortPivot(float arr[], int left, int right) {
    float temp;
    int mid, pivotIndex;

    // base case
    if (left >= right) {
        return;
    }

    // swap middle element to the end so partition() still works
    mid = (left + right) / 2;
    temp = arr[mid];
    arr[mid] = arr[right];
    arr[right] = temp;

    pivotIndex = partition(arr, left, right);

    quickSortPivot(arr, left, pivotIndex - 1);
    quickSortPivot(arr, pivotIndex + 1, right);
}