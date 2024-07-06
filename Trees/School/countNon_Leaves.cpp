int countNonLeaves(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }
    return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
}
