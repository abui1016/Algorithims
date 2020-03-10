// Heapsort: R.T.: O(nlogn)
#include <iostream>

using namespace std;

void maxHeapify(int* arr, int arrHeapSize, int i);
void buildMaxHeap(int* arr, int arrSize);
void heapSort(int* arr, int arrHeapSize);

void swap(int* arr, int src, int dst);
void printArr(int* arr, int arrSize);

int main(int argc,char **argv) {

    int arrSize;
	cin >> arrSize;

	int* arr;
    arr = new int[arrSize];
	 
    // Take in array values
	for (int i = 0; i < arrSize; i++){
		cin >> arr[i];
	}

    heapSort(arr, arrSize-1);

    printArr(arr, arrSize);

    delete[] arr;

    return 0;
}

void buildMaxHeap(int* arr, int arrSize) {
    int arrHeapSize = arrSize;
    for(int i = (arrSize/2); i >= 0; i--) { 
        maxHeapify(arr, arrHeapSize, i);
    }
}

void heapSort(int* arr, int arrHeapSize) {
    buildMaxHeap(arr, arrHeapSize);
    for(int i = arrHeapSize; i >= 1; i--) {
        swap(arr, 0, i); // Swap A[0] with A[i]
        arrHeapSize -= 1; // arrHeapSize = arrHeapSize - 1
        maxHeapify(arr, arrHeapSize, 0);
    }
}

void maxHeapify(int* arr, int arrHeapSize, int i) {
    int largest = 0;
    int l = (2 * i) + 1; // Left node
    int r = (2 * i) + 2; // Right node

    if(l <= arrHeapSize && arr[l] > arr[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if(r <= arrHeapSize && arr[r] > arr[largest]) {
        largest = r;
    }

    if(largest != i) {
        swap(arr, i, largest); // Swapping A[i] and A[largest]
        maxHeapify(arr, arrHeapSize, largest);
    }
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
