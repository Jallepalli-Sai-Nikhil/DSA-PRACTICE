int sumOfNonLeaves(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }
    return root->data + sumOfNonLeaves(root->left) + sumOfNonLeaves(root->right);
}
