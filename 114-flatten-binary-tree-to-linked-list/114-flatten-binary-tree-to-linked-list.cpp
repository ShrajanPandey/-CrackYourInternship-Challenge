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
    TreeNode* flatIt( TreeNode *root , TreeNode* pre ){
        
        if( root == NULL ){
            return pre;
        }
        
        pre = flatIt(root->right, pre);
        pre = flatIt(root->left, pre);
        
        root->right = pre;
        root->left = NULL;
        
        pre = root;
        return pre;
        
    }
        
    void flatten(TreeNode* root) {
        
        //iterative
        TreeNode *curNode = root;
        while( curNode != NULL ){
            
            if( curNode->left ){
                
                TreeNode *pre = curNode->left;
                while( pre->right ){
                    pre = pre->right;
                }
                pre->right = curNode->right;
                
                curNode->right = curNode->left;
                curNode->left = NULL;
                
            }
            curNode = curNode->right;
            
        }
        
    }
};