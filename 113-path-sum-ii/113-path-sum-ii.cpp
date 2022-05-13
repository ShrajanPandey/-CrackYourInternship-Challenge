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
    vector<vector<int>> ans;
    
    void fill(TreeNode *root , int targetSum , vector<int> &p ){
        
        if( root == NULL ){
            return ;
        }
                
        p.push_back(root->val);
        
        if( root->left == NULL && root->right == NULL ){
            
            if( targetSum - root->val == 0 ){
                ans.push_back(p);
            }

        }

        fill(root->left , targetSum - root->val, p);
        fill(root->right , targetSum - root->val ,p);
        p.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum ) {
        
        vector<int> v;
        fill(root , targetSum , v);
        return ans;
        
    }
};