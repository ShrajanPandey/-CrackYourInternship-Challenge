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
        
        vector<vector<int>> ans;
        
        if( root == NULL ){
            return ans;
        }
        
        deque <TreeNode *> level;
        level.push_back(root);
        bool ltor = 1;
        
        while( level.size() != 0 ){
            
            vector<int> l;
            
            int curLevel = level.size();
            for( int i = 0 ; i < curLevel ; ++i ){
                
                if( ltor ){
                    TreeNode *cur = level.front();
                    level.pop_front();
                    if( cur->left ){
                        level.push_back(cur->left);
                    }
                    if( cur->right ){
                        level.push_back(cur->right);
                    }
                    l.push_back(cur->val);
                }
                else{
                    TreeNode *cur = level.back();
                    level.pop_back();
                    if( cur->right ){
                        level.push_front(cur->right);
                    }
                    if( cur->left ){
                        level.push_front(cur->left);
                    }
                    l.push_back(cur->val);
                }
                
            }
            
            ans.push_back(l);
            ltor = !ltor;
            
        }
        
        return ans;
    }
};