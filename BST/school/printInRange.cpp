#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void findNearNodes(Node* root, int low, int high, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        
        // Traverse left subtree if current node's value is greater than low
        if (root->data > low) {
            findNearNodes(root->left, low, high, ans);
        }
        
        // Add current node's value if it's within the range
        if (root->data >= low && root->data <= high) {
            ans.push_back(root->data);
        }
        
        // Traverse right subtree if current node's value is less than high
        if (root->data < high) {
            findNearNodes(root->right, low, high, ans);
        }
    }
    
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        findNearNodes(root, low, high, ans);
        return ans;
    }
};

// Utility function to insert a new node with given key in BST
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

// Function to print a vector
void printVector(const vector<int>& vec) {
    cout << "Nodes within the given range are: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example usage:
    Node* root = nullptr;
    Solution solution;
    
    // Inserting nodes into BST
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 50);
    insert(root, 1);
    insert(root, 40);
    insert(root, 100);
    
    int low = 5;
    int high = 50;
    
    // Finding and printing nodes within the range [low, high]
    vector<int> result = solution.printNearNodes(root, low, high);
    printVector(result);
    
    return 0;
}
