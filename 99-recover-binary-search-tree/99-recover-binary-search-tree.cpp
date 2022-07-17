/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inOrder;
    
    void trav( TreeNode *root ){
        
        if( root == NULL ){
            return;
        }
        
        trav( root->left);
        inOrder.push_back(root->val);
        trav( root->right );
        
    }
    
    void swapVal( TreeNode *root ,int a , int b ){
        
        if( root == NULL ){
            return;
        }
        
        if( root->val == a ){
            root->val = b;
        }
        else if( root->val == b ){
            root->val = a;
        }
        
        swapVal( root->left , a, b);
        swapVal( root->right , a , b );
        
    }
    
    void recoverTree(TreeNode* root) {
        
        if( root == NULL ){
            return;
        }
        
        inOrder.clear();
        trav(root);
        
        vector<int> temp = inOrder;
        sort(temp.begin(),temp.end());
            
        int first = -1 , second = -1 ;
        
        for( int i = 0 ; i < temp.size() ; ++i ){
            if( temp[i] != inOrder[i] ){
                if( first == -1 ){
                    first = inOrder[i];
                }
                else if( second == -1 ){
                    second = inOrder[i];
                }
            }
        }
        
        swapVal( root ,first , second );
        
    }
};