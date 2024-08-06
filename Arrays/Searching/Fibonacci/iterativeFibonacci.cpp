#include <iostream>
using namespace std;

// Utility function to find the minimum of two elements
int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int x, int n) {
    // Initialize Fibonacci numbers
    int fibMMm2 = 0; // (m-2)'th Fibonacci number
    int fibMMm1 = 1; // (m-1)'th Fibonacci number
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci number

    // fibM is the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to be inspected, note that we compare arr[fibMMm2] with x
    while (fibM > 1) {
        // Check if fibMMm2 is a valid index
        int i = min(offset + fibMMm2, n - 1);

        // If x is greater than the value at index fibMMm2, cut the subarray array from offset to i
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // If x is less than the value at index fibMMm2, cut the subarray after i+1
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // element found. return index
        else {
            return i;
        }
    }

    // comparing the last element with x
    if (fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // element not found. return -1
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 70;
    int result = fibonacciSearch(arr, x, n);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}
