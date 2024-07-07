#include <iostream>

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform in-order traversal and find Kth smallest
void KSmallest(Node* root, int& ans, int& K) {
    if (!root)
        return;
    
    // Traverse left subtree first (for ascending order)
    KSmallest(root->left, ans, K);
    
    // Process current node
    K--;
    if (K == 0) {
        ans = root->data;
        return;
    }
    
    // If K becomes 0 or negative, we've found our answer, so we can return
    if (K < 0)
        return;
    
    // Traverse right subtree
    KSmallest(root->right, ans, K);
}

// Function to find the Kth smallest element in the BST
int kthSmallest(Node* root, int K) {
    int ans = -1; // Initialize ans to a default value
    KSmallest(root, ans, K);
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

    // Finding Kth smallest element
    int K = 3;
    int result = kthSmallest(root, K);
    
    std::cout << "The " << K << "th smallest element is: " << result << std::endl;

    return 0;
}