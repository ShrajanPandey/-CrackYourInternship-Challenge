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
    
    long long sum(TreeNode *root, long long &ans, long long target){
        
        if( root == NULL ){
            return 0;
        }
        
        int smallSum = root->val + sum(root->left, ans , target) + sum(root->right , ans , target);
        ans = max( smallSum*(target-smallSum) , ans );
        
        return smallSum;
        
    }
    
    int maxProduct(TreeNode* root) {
        
        long long ans = 0;
        long long totalSum = sum(root, ans ,0);
        
        sum(root , ans , totalSum);
        
        return ans%mod;
        
    }
};