#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    int sumOfKSmallestElements(int k) {
        int sum = 0;
        int count = 0;
        sumOfKSmallestElementsRec(root, k, count, sum);
        return sum;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void sumOfKSmallestElementsRec(Node* node, int k, int& count, int& sum) {
        if (node == nullptr || count >= k) {
            return;
        }
        sumOfKSmallestElementsRec(node->left, k, count, sum);
        if (count < k) {
            sum += node->data;
            count++;
        }
        sumOfKSmallestElementsRec(node->right, k, count, sum);
    }
};

int main() {
    BST tree;
    tree.insert(20);
    tree.insert(8);
    tree.insert(22);
    tree.insert(4);
    tree.insert(12);
    tree.insert(10);
    tree.insert(14);

    int k = 3;
    cout << "The sum of the " << k << " smallest elements in the BST is: " << tree.sumOfKSmallestElements(k) << endl;

    BST tree2;
    tree2.insert(10);
    tree2.insert(5);
    tree2.insert(11);
    tree2.insert(4);
    tree2.insert(7);
    tree2.insert(8);

    k = 2;
    cout << "The sum of the " << k << " smallest elements in the BST is: " << tree2.sumOfKSmallestElements(k) << endl;

    return 0;
}
