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
    vector<int> rightSideView(TreeNode* root) {
        
        if( root == NULL ){
            return {};
        }
        
        vector<int> ans;
        
        queue<TreeNode *> pend;
        pend.push(root);
        
        while( pend.size() ){
            
            int curLevel = pend.size();
            while( curLevel-- ){
                
                TreeNode *curNode = pend.front();
                pend.pop();
                
                if( curNode->left ){
                    pend.push(curNode->left);
                }
                if( curNode->right ){
                    pend.push(curNode->right);
                }
                
                if( curLevel == 0 ){
                    ans.push_back(curNode->val );
                }
                
            }
            
        }
        
        return ans;
        
    }
};