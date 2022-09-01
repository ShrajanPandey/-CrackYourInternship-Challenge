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
    int goodNodes(TreeNode* root, int maxi = INT_MIN) {
        
        if( root == NULL ){
            return 0;
        }
        
        int ans = 0;
        if( root->val >= maxi ){
            ++ans;
            maxi = root->val;
        }
        int a = goodNodes(root->left,maxi);
        int b = goodNodes(root->right,maxi);
        
        
        return a + b + ans;
        
    }
};