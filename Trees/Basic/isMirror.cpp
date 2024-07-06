#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
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

void inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

Node* mirror(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);

    return node;
}

bool isMirror(Node* a, Node* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a == nullptr || b == nullptr) {
        return false;
    }

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    Node* root1 = nullptr;
    root1 = insert(root1, 50);
    root1 = insert(root1, 30);
    root1 = insert(root1, 70);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);
    root1 = insert(root1, 60);
    root1 = insert(root1, 80);

    Node* root2 = nullptr;
    root2 = insert(root2, 50);
    root2 = insert(root2, 70);
    root2 = insert(root2, 30);
    root2 = insert(root2, 80);
    root2 = insert(root2, 60);
    root2 = insert(root2, 40);
    root2 = insert(root2, 20);

    root2 = mirror(root2);

    std::cout << "Tree 1 (in-order traversal): ";
    inOrderTraversal(root1);
    std::cout << std::endl;

    std::cout << "Tree 2 (in-order traversal after mirroring): ";
    inOrderTraversal(root2);
    std::cout << std::endl;

    if (isMirror(root1, root2)) {
        std::cout << "The trees are mirrors of each other." << std::endl;
    } else {
        std::cout << "The trees are not mirrors of each other." << std::endl;
    }

    return 0;
}
