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

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if( root == NULL ){
            return ans;
        }
        
        stack<TreeNode*> q;
        TreeNode* cur = root;
        
        while( cur != NULL || q.empty() != 1 ){
  
            while( cur != NULL ){
                q.push(cur);
                cur = cur->left;
            }
            
            cur = q.top();
            ans.push_back(cur->val);
            q.pop();
            
            cur = cur->right;
            
        }
        
        return ans;
       
    }
};