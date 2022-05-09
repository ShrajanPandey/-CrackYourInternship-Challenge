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
    string smallestFromLeaf(TreeNode* root) {
        
        queue<pair<TreeNode*,string>> level;
        string ans = "";
        level.push({root,(char)(root->val + 'a') + ans});
        
        while( level.empty() != 1 ){
            
            int curLevel = level.size();
            for( int i = 0 ; i < curLevel ; ++i ){
                
                pair<TreeNode*,string> cur = level.front();
                level.pop();
        
                if( cur.first->left ){
                    char n = cur.first->left->val + 'a';
                    level.push({cur.first->left,n+cur.second});
                }
                if( cur.first->right ){
                    char n = cur.first->right->val + 'a';
                    level.push({cur.first->right,n+cur.second});
                }
                if(cur.first->right == NULL && cur.first->left == NULL ){

                    if( ans == "" ){
                        ans = cur.second;
                    }
                    else{
                        ans = min(ans , cur.second);
                    }
                }

            }
            
        }
        
        return ans;
        
    }
};