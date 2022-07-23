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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if( root == NULL ){
            return {};
        }
        
        vector<int> ans;
        stack<TreeNode *> helper;
        helper.push(root);
        
        while( helper.size() ){
        
            TreeNode *cur = helper.top();
            helper.pop();
            
            ans.push_back(cur->val);
            if( cur->left ){
                helper.push(cur->left);
            }
            if( cur->right ){
                helper.push(cur->right);
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};