#include <iostream>
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

void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

Node* LCA(Node* root, int n1, int n2) {
    if (root == nullptr)
        return nullptr;

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    return root;
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);

    cout << "In-Order traversal: ";
    inorder(root);
    cout << endl;

    int n1 = 10, n2 = 20;
    Node* lcaNode = LCA(root, n1, n2);
    if (lcaNode != nullptr) {
        cout << "The LCA of (" << n1 << "," << n2 << ") is: " << lcaNode->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    n1 = 20, n2 = 30;
    lcaNode = LCA(root, n1, n2);
    if (lcaNode != nullptr) {
        cout << "The LCA of (" << n1 << "," << n2 << ") is: " << lcaNode->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
