#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the median of a vector of integers
double Median(vector<int>& nums) {
    // Sort the vector
    sort(nums.begin(), nums.end());

    // Calculate the size of the vector
    int n = nums.size();

    // Check if the size of the vector is odd or even
    if (n % 2 != 0) {
        // If odd, return the middle element
        return nums[n / 2];
    } else {
        // If even, return the average of the two middle elements
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
}

// Function to traverse the BST and collect values into a vector
void traverseAndCollect(Node* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }

    traverseAndCollect(root->left, ans);
    ans.push_back(root->data);
    traverseAndCollect(root->right, ans);
}

// Function to find the median of values in a BST
double findMedian(Node* root) {
    vector<int> ans;
    traverseAndCollect(root, ans); // Collect all values into the vector

    return Median(ans); // Calculate and return the median
}

int main() {
    // Example usage
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    double median = findMedian(root);
    cout << "Median of the BST: " << median << endl;

    return 0;
}
