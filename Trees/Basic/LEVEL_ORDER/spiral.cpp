
vector<int> spiralLevelOrder(Node* root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            ans.push_back(node->data);

            if (node->left != nullptr)
                s2.push(node->left);
            if (node->right != nullptr)
                s2.push(node->right);
        }

        while (!s2.empty()) {
            Node* node = s2.top();
            s2.pop();
            ans.push_back(node->data);

            if (node->right != nullptr)
                s1.push(node->right);
            if (node->left != nullptr)
                s1.push(node->left);
        }
    }
    return ans;
}

These functions implement reverse level order traversal (reverseLevelOrder) and spiral level order traversal (spiralLevelOrder). The reverseLevelOrder function uses a queue and pushes nodes in the reverse order they are popped from the queue. The spiralLevelOrder function uses two stacks (s1 and s2) to alternate between pushing nodes from left to right and right to left.

You can call these functions in the main function to test their functionality. For example:
int main() {
    // Example usage
    Node* root = new Node(1);
    // ...

    vector<int> spiralResult = spiralLevelOrder(root);
    cout << "Spiral Level Order: ";
    for (int val : spiralResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}