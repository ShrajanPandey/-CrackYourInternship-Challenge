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
    void inorder(TreeNode *root ){
        if( root == NULL ){
            return;
        }    
        
        inorder(root->left);
        inOrder.push_back(root->val);
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        for( int i = 1 ; i < inOrder.size() ; ++i ){
            if( inOrder[i-1] >= inOrder[i] ){
                return 0;
            }
        }
        return 1;
        
    }
};