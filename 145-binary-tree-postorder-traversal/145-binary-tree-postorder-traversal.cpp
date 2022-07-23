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
        TreeNode *cur = root, *last = NULL ;
        
        while( cur || helper.size() ){
            
            if( cur != NULL ){
                helper.push(cur);
                cur = cur->left;
            }
            else{
                
                TreeNode *node = helper.top();
                if( node->right != NULL && node->right != last ){
                    cur = node->right;
                }
                else{
                    ans.push_back(node->val);
                    last = node;
                    helper.pop();
                }
                
            }
            
        }
        
        
        return ans;
        
    }
};