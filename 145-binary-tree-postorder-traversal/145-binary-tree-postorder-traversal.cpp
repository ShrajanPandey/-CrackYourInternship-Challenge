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
        
        stack<TreeNode *> st1 , st2;
        st1.push(root);
        
        while( st1.empty() != 1 ){
            
            TreeNode *cur = st1.top();
            st1.pop();
            
            st2.push(cur);
            if( cur->left ){
                st1.push(cur->left);
            }
            if( cur->right ){
                st1.push(cur->right);
            }
            
        }
        
        vector<int> ans;
        while( st2.empty() != 1 ){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        
        return ans;
    }
};