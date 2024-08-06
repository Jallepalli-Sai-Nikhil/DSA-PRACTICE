#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }

        // If x greater, ignore left half
        if (arr[mid] < x) {
            low = mid + 1;
        }
        // If x is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}
