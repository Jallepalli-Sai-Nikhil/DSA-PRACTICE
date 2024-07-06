int sumOfBT(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumOfBT(root->left) + sumOfBT(root->right);
}
