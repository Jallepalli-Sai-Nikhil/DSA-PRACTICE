#include <iostream>
#include <vector>

class BinaryTree {
public:
    BinaryTree(int size) : size(size) {
        tree.resize(size, -1); // Initialize all elements with -1 (indicating empty)
    }

    void setRoot(int value) {
        tree[0] = value;
    }

    void setLeft(int parentIndex, int value) {
        int leftIndex = 2 * parentIndex + 1;
        if (leftIndex < size) {
            tree[leftIndex] = value;
        }
    }

    void setRight(int parentIndex, int value) {
        int rightIndex = 2 * parentIndex + 2;
        if (rightIndex < size) {
            tree[rightIndex] = value;
        }
    }

    void printTree() {
        for (int i = 0; i < size; ++i) {
            if (tree[i] != -1) {
                std::cout << "Node " << i << ": " << tree[i] << std::endl;
            } else {
                std::cout << "Node " << i << ": " << "None" << std::endl;
            }
        }
    }

private:
    int size;
    std::vector<int> tree;
};

int main() {
    BinaryTree bt(7); // Create a binary tree of size 7

    bt.setRoot(1);
    bt.setLeft(0, 2);
    bt.setRight(0, 3);
    bt.setLeft(1, 4);
    bt.setRight(1, 5);
    bt.setLeft(2, 6);

    bt.printTree();

    return 0;
}
