/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if( root == NULL ){
            return root;
        }
        
        queue<Node *> pending;
        pending.push(root);
        
        while( pending.size() != 0 ){
            
            int n = pending.size();
            Node *pre = NULL,*cur = NULL;
        
            for( int i = 0 ; i < n  ; ++i ){
                cur = pending.front();
                pending.pop();
                if( cur->left ){
                    pending.push(cur->left);
                }
                if( cur->right ){
                    pending.push(cur->right);
                }
                if( i != 0 ){
                    pre->next = cur;
                }
                pre = cur;
            }
        
        }
    
        return root;
    }
};