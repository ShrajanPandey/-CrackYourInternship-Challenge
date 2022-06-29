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
    int mod = 1e9 + 7;
    
    long long sum(TreeNode *root){
        
        if( root == NULL ){
            return 0;
        }
        
        root->val += sum(root->left) + sum(root->right);
        return root->val;
        
    }
    
    void maximumProduct( TreeNode *root , long long total , long long &ans  ){
        
        if( root == NULL ){
            return;
        }
        
        ans = max(ans , (root->val*(total-root->val)));
        
        maximumProduct( root->left , total , ans );
        maximumProduct( root->right , total , ans );
        
    }
    
    int maxProduct(TreeNode* root) {
    
        long long totalSum = sum(root);
        long long ans = 0;
        
        maximumProduct(root , totalSum , ans );
        
        return ans%mod;
        
    }
};