#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to check if the binary tree is a BST
bool isBSTUtil(Node* node, int min, int max) {
    // An empty tree is a BST
    if (node == nullptr) {
        return true;
    }

    // False if this node violates the min/max constraint
    if (node->data < min || node->data > max) {
        return false;
    }

    // Otherwise check the subtrees recursively
    // tightening the min or max constraint
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

// Function to check if the binary tree is a BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Function to insert a key into the BST
Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

// Function to perform inorder traversal of the BST
void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-Order traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root)) {
        cout << "The tree is a BST" << endl;
    } else {
        cout << "The tree is not a BST" << endl;
    }

    return 0;
}
