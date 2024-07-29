/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    vector<Node *> nodesAtOddLevels(Node *root)
    {
        vector<Node*> res;
        if(!root)
          return res;
          
        queue<Node*> q;
        q.push(root);
        
        int level= 1;
        
        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                Node* node = q.front();
                q.pop();
                
                if(level % 2 != 0){
                    res.push_back(node);
                }
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ++level;
        }
        return res;
    }
};
