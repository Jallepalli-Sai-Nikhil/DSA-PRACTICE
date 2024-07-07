#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform reverse in-order traversal and find Kth largest
void KLargest(Node* root, int& ans, int& K) {
    if (!root)
        return;
    
    // Traverse right subtree first (for descending order)
    KLargest(root->right, ans, K);
    
    // Process current node
    K--;
    if (K == 0) {
        ans = root->data;
        return;
    }
    
    // If K becomes 0 or negative, we've found our answer, so we can return
    if (K < 0)
        return;
    
    // Traverse left subtree
    KLargest(root->left, ans, K);
}

// Function to find the Kth largest element in the BST
int kthLargest(Node* root, int K) {
    int ans = -1; // Initialize ans to a default value
    KLargest(root, ans, K);
    return ans;
}

// Helper function to insert a new node into the BST
Node* insert(Node* root, int val) {
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Main function to test the implementation
int main() {
    Node* root = nullptr;
    
    // Inserting nodes
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 7);

    // Finding Kth largest element
    int K = 3;
    int result = kthLargest(root, K);
    
    std::cout << "The " << K << "th largest element is: " << result << std::endl;

    return 0;
}