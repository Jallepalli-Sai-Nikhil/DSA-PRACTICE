vector<int> reverseLevelOrder(Node* root) {
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

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

            ans.push_back(node->data);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}