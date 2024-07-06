#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* node, int value){

    if(node == nullptr){
        return new Node(value);
    }

    if(value < node -> data){
        node -> left = insert(node -> left, value);
    }
    else if(value > node->data){
        node -> right = insert(node -> right, value);
    }

    return node;
}

void preorder(Node* node){
    if(node != nullptr){

        cout << node -> data << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
}

int main(){
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);

    cout<<"In-Order traversal : ";
    preorder(root);
    cout<<endl;

    return 0;
}