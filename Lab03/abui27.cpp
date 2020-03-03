// Divide and Conquer max sub array: R.T.: O(nlogn)
#include <iostream>

#define MAX_INT 2147483647

#define LOW_INT -2147483647

using namespace std;

int findMaxSubArray(int* arr, int l, int h);

int findMaxCrossSubArray(int* arr, int l, int m, int h);

int main(int argc,char **argv) {
    
    int arrSize = 0;
	
	cin >> arrSize;

	int* arr;
    arr = new int[arrSize];
	
    // Fill in array 
	for (int i = 0; i < arrSize; i++){
		cin >> arr[i];
	}

    if(arrSize == 0) {
        cout << findMaxSubArray(arr, 0, arrSize);
    } else {
        cout << findMaxSubArray(arr, 0, arrSize-1);
    }

    delete[] arr;

    return 0;
}

int findMaxSubArray(int* arr, int l, int h) {
    if(h == l) { // h = high, l = low in this case
        return(arr[l]); // Base case: Only one element in array
    } else {
        int mid = (l + h) / 2;

        int l_Sum = findMaxSubArray(arr, l, mid);
        int r_Sum = findMaxSubArray(arr, mid+1, h);
        int x_Sum = findMaxCrossSubArray(arr, l, mid, h);

        if(l_Sum >= r_Sum && l_Sum >= x_Sum) {
            return(l_Sum);
        } else if(r_Sum >= l_Sum && r_Sum >= x_Sum) {
            return (r_Sum);
        } else {
            return (x_Sum);
        }
    }
}

int findMaxCrossSubArray (int* arr, int l, int m, int h) {
    int l_Sum = LOW_INT; // left_Sum = -2147483647
    int sum = 0;
    for(int i = m; i >= l; i--) {
        sum += arr[i];
        if(sum > l_Sum) {
            l_Sum = sum;
        }
    }
    int r_Sum = LOW_INT; // right_Sum = -2147483647
    sum = 0; // Reset sum to 0 
    for(int j = m+1; j <= h; j++) {
        sum += arr[j];
        if(sum > r_Sum) {
            r_Sum = sum;   
        }
    }
    return(l_Sum + r_Sum);
}