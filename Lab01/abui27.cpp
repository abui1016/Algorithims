//Insertion Sort: R.T.:O(n^2)

#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void insertionSort(int* arr, int arrSize);

int main(int argc,char **argv) {

    int* arr;
    int arrSize = 1;

    // Take in user input for array size 
    // Create array size arrSize
    cin >> arrSize;
    arr = new int[arrSize];

    // Take in values for each array index
    for(int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, arrSize);

    delete[] arr;
    
}

void insertionSort(int* arr, int arrSize) {
    int key = 0;
    int i = 0;
    for(int j = 1; j < arrSize; j++) {
        key = arr[j];
        i = j - 1;
        // while "i" is not the first index and while arr[i] is greater than key
        while(i >= 0 && arr[i] > key) { 
            arr[i+1] = arr[i]; // Swap; key holds value for arr[i+1]
            i = i - 1; // Decrease i -> going backwards in array
        }
        arr[i+1] = key; 
        // Print out each iteration of loop
        for(int k = 0; k <= j; k++) {
            cout << arr[k] << ";";
        }
        cout << endl;
    }
}
