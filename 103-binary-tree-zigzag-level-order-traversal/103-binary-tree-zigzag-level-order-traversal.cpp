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
        
        stack<TreeNode *> LtoR,RtoL;
        LtoR.push(root);
        
        bool ltor = 1;
        while( LtoR.size() != 0 || RtoL.size() != 0 ){
            
            vector<int> curLevel;
            
            if( ltor ){
                
                while( LtoR.size() != 0 ){
                    
                    TreeNode *cur = LtoR.top();
                    LtoR.pop();
                    
                    if( cur->left ){
                        RtoL.push(cur->left);
                    }
                    if( cur->right ){
                        RtoL.push(cur->right);
                    }
                    
                    curLevel.push_back(cur->val);
                    
                }
                ltor = 0;
                
            }
            else{
                
                while( RtoL.size() != 0 ){
                    
                    TreeNode *cur = RtoL.top();
                    RtoL.pop();
                    
                    if( cur->right ){
                        LtoR.push(cur->right);
                    }
                    if( cur->left ){
                        LtoR.push(cur->left);
                    }
                    
                    curLevel.push_back(cur->val);
                    
                }
                ltor = 1;
                
            }
            
            ans.push_back(curLevel);
            
        }
        
        return ans;
        
    }
};