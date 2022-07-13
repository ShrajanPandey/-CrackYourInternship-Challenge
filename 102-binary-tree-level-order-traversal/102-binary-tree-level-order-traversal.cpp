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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( root == NULL ){
            return ans;
        }
        
        queue<TreeNode*> pending;
        pending.push(root);
        
        while( !pending.empty() ){
            vector<int> level;

            int cnt = pending.size();
            for( int i = 0 ; i < cnt ; ++i ){
                
                TreeNode *cur = pending.front();
                pending.pop();
                level.push_back(cur->val);
                if( cur->left )
                    pending.push(cur->left);
                if( cur->right )
                    pending.push(cur->right);
            
            }
            
            ans.push_back(level);
        }
        
        return ans;
        
    }
};