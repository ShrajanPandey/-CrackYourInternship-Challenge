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
    int maxPath(TreeNode *root , int &ans){
        
        if( root == NULL ){
            return 0;
        }
        
        int left = maxPath(root->left , ans);
        int right = maxPath(root->right, ans);
        
        if(left < 0 ){
            left = 0;
        }
        if( right < 0 ){
            right = 0;
        }
        
        int an = max(ans , root->val + left + right);
        ans = max( ans , an); 
        
        return root->val + max( left , right);
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        maxPath(root , ans);
        return ans;
        
    }
};