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
    map<TreeNode *,int> m;
    
    int maxAmount( TreeNode *root ){
        
        if( root == NULL ){
            return 0;
        }
        
        if( m.count(root) ){
            return m[root];
        }
        
        int ans = maxAmount(root->left) + maxAmount(root->right);
        int sum = root->val;
        
        if( root->left ){
            sum += maxAmount(root->left->left) + maxAmount(root->left->right);
        }
        if( root->right ){
            sum += maxAmount(root->right->right) + maxAmount(root->right->left);
        }
        
        return m[root] = max( ans, sum);
        
    }
    
    int rob(TreeNode* root) {
        
        m.clear();
        return maxAmount(root);
        
    }
};