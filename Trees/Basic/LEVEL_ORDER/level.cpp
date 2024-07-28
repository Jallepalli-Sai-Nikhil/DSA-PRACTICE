#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> levelOrder(Node* root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front();

            q.pop();
            ans.push_back(node->data);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
    return ans;
}

int main() {
    // Example usage
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = levelOrder(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}