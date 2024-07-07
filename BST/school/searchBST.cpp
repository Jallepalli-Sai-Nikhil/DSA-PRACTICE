#include <iostream>

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the BST
bool search(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) {
            return true;
        } else if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

// Function to perform inorder traversal of the BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

// Main function to demonstrate insert, search, and inorder traversal
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "Inorder traversal of the given tree: ";
    inorder(root);
    std::cout << std::endl;

    int key = 40;
    if (search(root, key)) {
        std::cout << "Key " << key << " found in the BST." << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the BST." << std::endl;
    }

    key = 90;
    if (search(root, key)) {
        std::cout << "Key " << key << " found in the BST." << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the BST." << std::endl;
    }

    return 0;
}
