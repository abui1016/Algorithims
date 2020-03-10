// Quicksort: R.T.: O(nlogn)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Functions for sorting
int partition(int* arr, int l, int r);
int randomPartition(int* arr, int l, int r);
void randomQuickSort(int* arr, int l, int r);

// Helper functions
int randomNum(int l, int r);
void swap(int* arr, int src, int dst);
void printArr(int* arr, int arrSize);

using namespace std;

int main(int argc, char **argv) {

    // Generate array
    int arrSize = 0;
    cin >> arrSize;

    int* arr;
    arr = new int[arrSize];

    // Fill in array
    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    randomQuickSort(arr, 0, arrSize-1);
    printArr(arr, arrSize);

    delete[] arr;

    return 0;
}

int partition(int* arr, int l, int r) { 
    int x = arr[r]; // x = last element of array
    int i = l-1; // i = left index - 1, in case need to swap with index 0
    for(int j = l; j < r; j++) { // j to r-1
        if(arr[j] <= x) {
            i += 1;
            swap(arr, i, j); // swap arr[i] with arr[j]
        }
    }
    swap(arr, i+1, r); // swap next element with last element
    return i+1;
}

int randomPartition(int* arr, int l, int r) {
    int i = randomNum(l, r); // select an element as the pivot
    swap(arr, r, i); // swap arr[i] and arr[r], r is the end of the array
    return partition(arr, l, r);
}

void randomQuickSort(int* arr, int l, int r) {
    if(l < r) {
        int q = randomPartition(arr, l, r);
        randomQuickSort(arr, l, q-1); // Sort left side
        randomQuickSort(arr, q+1, r); // Sort right side
    }
}

int randomNum(int l, int r) {
    srand(time(NULL));
    // rand() % (how many numbers included in range) + (lowest number in range)
    int randomNum = rand() % (r - l + 1) + l ;
    return randomNum;
}

void swap(int* arr, int src, int dst) {
    int temp = arr[src];
    arr[src] = arr[dst];
    arr[dst] = temp;
}

void printArr(int* arr, int arrSize) {
     for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << ";";
    }
}