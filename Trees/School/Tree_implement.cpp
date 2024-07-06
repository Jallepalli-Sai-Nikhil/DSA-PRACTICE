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

void inorder(Node* node){
    if(node != nullptr){
        inorder(node -> left);
        cout << node -> data << " ";
        inorder(node -> right);
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
    inorder(root);
    cout<<endl;

    return 0;
}