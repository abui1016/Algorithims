// Merge Sort: R.T. O(nlogn)
#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void mergeSort(int* arr, int l, int r); 

void merge(int* arr, int l, int m, int e); 

int main(int argc,char **argv) {
    
    int arrSize;
	
	cin >> arrSize;

	int* arr;
    arr = new int[arrSize];
	
    // Fill in array 
	for (int i = 0; i < arrSize; i++){
		cin >> arr[i];
	}

	mergeSort(arr, 0, arrSize-1);
	
    // Print out sorted array
	for(int i = 0; i < arrSize; i++){
		cout << arr[i] << ";";
	}

    delete[] arr;

    return 0;
}

void merge(int* arr, int l, int m, int r) { 

    int i, j, k; 
    int n1 = m - l + 1; // Mid - first index + 1
    int n2 =  r - m; // Last index - middle index

    int L[n1], R[n2]; // Initialize temp arrays
  
    // Copy elements from main array into temp arrays
    for (i = 0; i < n1; i++) {  
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; 
    }

    i = 0; // First index of first subarray
    j = 0; // First index of second subarray
    k = l; // First index of merged subarray
	
    while (i < n1 && j < n2) { // n1 and n2 are lengths of temp arrays 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    // When array is not split into 2 even halves
    // Retrieve remaining elements L[]
    while (i < n1) {
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    // Retrieve remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int* arr, int l, int r) {
 
    if (l < r) {
        int m = l + (r - l)/2; // avoids seg fault

        // Sort first half and and second half of array
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 

        // Merge into single array
        merge(arr, l, m, r); 
    } 
} 
