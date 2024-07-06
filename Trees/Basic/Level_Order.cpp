#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, int value){
    if(node == NULL){
        return new Node(value);
    }

    if(value < node->data){
        node->left = insert(node->left, value);
    } else if(value > node->data){
        node->right = insert(node->right, value);
    }

    return node;
}

vector<int> level(Node* root){

    vector<int> result;
    if(root == nullptr){
        return result;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();

        for(int i=0;i<size;++i){
            Node* temp = q.front();
            q.pop();

            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
            result.push_back(temp->data);
        }
    }
    return result;
}

int main() {
    Node* root = NULL;

    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    cout << "Level-Order traversal of the constructed AVL tree is: "<<endl;
    vector<int> ans = level(root);
    for(auto i: ans) 
        cout<<i<<" ";

    return 0;
}