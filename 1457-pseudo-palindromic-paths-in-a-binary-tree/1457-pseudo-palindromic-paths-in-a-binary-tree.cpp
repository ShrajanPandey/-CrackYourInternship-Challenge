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
    int palindromicPaths( TreeNode *root , vector<int> &count ){
        
        if( root == NULL ){
            return 0;
        }
        
        count[root->val]++;
        
        if( root->left == NULL && root->right == NULL ){
            int odd = 0;
            for( int i = 1 ; i < 10 ; ++i ){
                if( count[i] & 1 ){
                    ++odd;
                }
            }
            count[root->val]--;
            return (odd <= 1);
        }
        
        int ans = palindromicPaths( root->left , count ) + palindromicPaths( root->right , count);
        count[root->val]--;
        
        return ans;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> count(10, 0);
        return palindromicPaths( root , count);
        
    }
};