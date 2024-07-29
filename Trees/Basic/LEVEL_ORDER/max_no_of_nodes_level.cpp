#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int maxNodeLevel(Node* root) {
    if (!root) {
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;
    int maxNodes = 0;
    int maxLevel = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        if (levelSize > maxNodes) {
            maxNodes = levelSize;
            maxLevel = level;
        }

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        level++;
    }
    return maxLevel;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

// Example usage
int main() {
    Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->left->right->left = newNode(5);
    root->right->right = newNode(8);

    cout << "Level with maximum nodes: " << maxNodeLevel(root) << endl;

    return 0;
}
