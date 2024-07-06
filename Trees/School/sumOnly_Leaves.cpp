int sumOfLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
    return sumOfLeaves(root->left) + sumOfLeaves(root->right);
}
