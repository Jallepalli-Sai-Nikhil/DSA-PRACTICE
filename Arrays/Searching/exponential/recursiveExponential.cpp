#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    // If the target value is at the first position
    if (arr[0] == x) {
        return 0;
    }

    // Find range for binary search
    int i = 1;
    while (i < n && arr[i] <= x) {
        i = i * 2;
    }

    // Perform binary search in the found range
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 70;
    int result = exponentialSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}
