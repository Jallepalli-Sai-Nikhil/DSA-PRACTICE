#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        // Estimate the position using the interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));

        if (arr[pos] == x) {
            return pos;
        }

        if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;
    int result = interpolationSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}
