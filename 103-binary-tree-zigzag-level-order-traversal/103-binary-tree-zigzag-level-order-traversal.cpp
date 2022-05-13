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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> levelOrder;
        levelOrder.push(root);
        vector<vector<int>> ans;
        int h = 1;
        
        if( root == NULL ){
            return ans;
        }
        
        while( levelOrder.empty() != 1 ){
            
            vector<int> level;
            int curLevel = levelOrder.size();
            
            for( int i = 0 ; i < curLevel ; ++i ){
                
                TreeNode* cur = levelOrder.front();
                levelOrder.pop();
                
                if( cur->left ){
                    levelOrder.push(cur->left);
                }
                if( cur->right ){
                    levelOrder.push(cur->right);
                }
                
                level.push_back(cur->val);
                
            }
            
            if( h&1 ){
                ans.push_back(level);
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
            ++h;
            
        }
        
        return ans;
        
    }
};