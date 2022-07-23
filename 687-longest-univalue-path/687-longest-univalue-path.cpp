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
    int ans = 0;
    
    int longestPath(TreeNode *root , int val ){
        
        if( root == NULL ){
            return 0;
        }
        
        int left = longestPath(root->left , root->val);
        int right = longestPath(root->right , root->val);
        // cout << left << ' ' << right <<  " " << root->val << " " << ans << endl;
        ans = max( ans , left + right );
        
        if( root->val != val ){
            return 0;
        }
        
        return 1 + max( left , right );  
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        ans = 0;
        if( root == NULL || (root->right == NULL && root->left == NULL) ){
            return 0;
        }
        
        
        longestPath(root , root->val);
        return ans;
        
    }
};