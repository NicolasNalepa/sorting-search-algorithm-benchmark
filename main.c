#include "algorithms.h"

void loadArray(const char *filename, float floatArr[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    
    int index = 0;

    while (index < size && fscanf(file, "%f%*[, \n]", &floatArr[index]) == 1) {
        index++;
    }

    fclose(file);
}

int main(void) {
    float arr[MAX_ARRAY_SIZE];
    char *filename = "data.csv";
    int indices[MAX_ARRAY_SIZE];
    int count, index;
    clock_t start, end;
    double time_spent;

    // ---- PART 1: BENCHMARKING ----

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    insertionSort(arr, MAX_ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort Execution time: %.6f seconds\n", time_spent);

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    bubbleSort(arr, MAX_ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort Execution time: %.6f seconds\n", time_spent);

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    selectionSort(arr, MAX_ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort Execution time: %.6f seconds\n", time_spent);

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    mergeSort(arr, MAX_ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort Execution time: %.6f seconds\n", time_spent);

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    quickSort(arr, MAX_ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort Execution time: %.6f seconds\n", time_spent);

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    start = clock();
    hybridMergeSort(arr, 0, MAX_ARRAY_SIZE - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Hybrid Merge Sort Execution time: %.6f seconds\n", time_spent);

    // ---- PART 2: SORTING VARIANTS ----

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    selectionSortRange(arr, 10, 50, MAX_ARRAY_SIZE);
    printf("selectionSortRange done\n");

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    insertionSortFrom(arr, MAX_ARRAY_SIZE, 100);
    printf("insertionSortFrom done\n");

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    bubbleSortFrontAndRear(arr, 10, 10, MAX_ARRAY_SIZE);
    printf("bubbleSortFrontAndRear done\n");

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    mergeSortFirstHalf(arr, MAX_ARRAY_SIZE);
    printf("mergeSortFirstHalf done\n");

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    quickSortPivot(arr, 0, MAX_ARRAY_SIZE - 1);
    printf("quickSortPivot done\n");

    // ---- PART 3: SEARCHING ----

    loadArray(filename, arr, MAX_ARRAY_SIZE);
    index = linearSearch(arr, MAX_ARRAY_SIZE, arr[50]);
    printf("linearSearch: found at index %d\n", index);

    count = linearSearchAll(arr, MAX_ARRAY_SIZE, arr[50], indices);
    printf("linearSearchAll: found %d matches\n", count);

    mergeSort(arr, MAX_ARRAY_SIZE);
    index = binarySearch(arr, MAX_ARRAY_SIZE, arr[50]);
    printf("binarySearch: found at index %d\n", index);

    index = binarySearchFirst(arr, MAX_ARRAY_SIZE, arr[50]);
    printf("binarySearchFirst: found at index %d\n", index);

    index = ternarySearch(arr, 0, MAX_ARRAY_SIZE - 1, arr[50]);
    printf("ternarySearch: found at index %d\n", index);

    return 0;
}