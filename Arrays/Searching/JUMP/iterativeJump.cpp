#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    // Finding the block where the element is present
    while (prev < n && arr[min(step, n)-1] < x) {
        prev = step;
        step += sqrt(n);
    }

    // Linear search within the block
    for (int i = prev; i < n && i < step; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = jumpSearch(arr, n, x);
    if (index != -1) {
        cout << "Number " << x << " is at index " << index << endl;
    } else {
        cout << "Number " << x << " is not in the array" << endl;
    }
    return 0;
}
