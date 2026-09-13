#include "algorithms.h"

/*
Purpose:
    Searches an unsorted array of floats for a target value using linear search
Parameters:
    arr[]  - array of floats to search
    size   - number of elements in the array
    target - value to search for
Example:
    Input:  [3.2, 1.5, 4.8], target = 1.5
    Output: 1
Effect:
    None, this does not modify the array 
Return:
    index of the target if found, -1 if not found
*/

int linearSearch(float arr[], int size, float target) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;

}

/*
Purpose:
    searches a sorted array of floats for a target value using binary search
Parameters:
    arr[]  - sorted array of floats to search
    size   - number of elements in the array
    target - value to search for
Example:
     Input:  [1.5, 3.2, 4.8], target = 3.2
    Output: 1
Effect:
    None, does not modify the array
Return:
    index of the target if found, -1 if not 
*/

int binarySearch(float arr[], int size, float target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

         if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;

}

/*
Purpose: 
    searches an array of floats for all occurrences of a target value using linear 
    search and stores all matching indices 
Parameters:
    arr[]     - array of floats to search
    size      - number of elements in the array
    target    - value to search for
    indices[] - array to store the indices of all matches
Example:
    Input:  [3.2, 1.5, 3.2, 4.8], target = 3.2
    Output: indices = [0, 2], returns 2
Effect:
    Fills the indices array with all positions where target was found.
Return:
    Number of matches found.
*/

int linearSearchAll(float arr[], int size, float target, int indices[]) {
    int i;
    int count = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            indices[count] = i;
            count++;
        }
    }

    return count;

}

/* 
Purpose:
    Searches a sorted array of floats for the first occurrence of a 
    duplicate target value using binary search 
Parameters: 
    arr[]  - sorted array of floats to search
    size   - number of elements in the array
    target - value to search for
Example:
    Input:  [1.2, 2.5, 3.4, 3.4, 3.4, 6.8, 8.1], target = 3.4
    Output: 2
    Input:  [1.2, 2.5, 3.4, 3.4, 3.4, 6.8, 8.1], target = 2.5
    Output: -1 (not a duplicate)
Effect:
    None. Does not modify the array 
Return:
    Index of first occurrence if target is a duplicate, - 1 otherwise
*/

int binarySearchFirst(float arr[], int size, float target) {
    int left = 0;
    int right = size - 1;
    int mid;
    int result = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // keep searching the left for the first occurrence 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        
    }

    //check if its a duplicate 
    if (result != -1) {
        if((result + 1 < size && arr[result + 1] == target) ||
        (result - 1 >= 0 && arr[result - 1] == target)) {
            return result;
        }
    }

    return -1;

}

/*
Purpose:
    searches a sorted array of floats for a target value that uses ternary search,
    which divides the array into three different parts using two midpoints.
Parameters:
     arr[]  - sorted array of floats to search
    left   - starting index of the search range
    right  - ending index of the search range
    target - value to search for
Example:
    Input:  [1.5, 2.1, 3.2, 4.8, 6.0], left=0, right=4, target=3.2
    Output: 2
Effect:
    None, does not modify the array 
Return:
    Index if target is found, -1 if not.
*/

int ternarySearch(float arr[], int left, int right, float target) {
    int mid1, mid2;

    //base case
    if (left > right) {
        return -1;
    }

    // divide the array into three parts 
    mid1 = left + (right - left) / 3;
    mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) {
        return mid1;
    }

    if (arr[mid2] == target) {
        return mid2;
    }

    // search for the third 
    if (target < arr[mid1]) {
        return ternarySearch(arr, left, mid1 - 1, target);

    } else if (target > arr[mid2]) {
        return ternarySearch(arr, mid2 + 1, right, target);

    } else {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }

}