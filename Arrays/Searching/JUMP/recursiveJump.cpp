#include <iostream>
#include <cmath>
using namespace std;

int linearSearch(int arr[], int start, int end, int x) {
    for (int i = start; i < end; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int jumpSearchRecursive(int arr[], int n, int x, int step, int prev) {
    if (prev >= n || arr[prev] > x) {
        return linearSearch(arr, prev - step, prev, x);
    }
    if (arr[prev] == x) {
        return prev;
    }
    return jumpSearchRecursive(arr, n, x, step, prev + step);
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int step = sqrt(n);

    int index = jumpSearchRecursive(arr, n, x, step, step);
    if (index != -1) {
        cout << "Number " << x << " is at index " << index << endl;
    } else {
        cout << "Number " << x << " is not in the array" << endl;
    }
    return 0;
}
