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
    int ans = 0;
    set<pair<TreeNode*,TreeNode*>> m;
    
    void noOfPaths( TreeNode *root , long long target , TreeNode *parent ){
    
        if( root == NULL ){
            return;
        }

        target -= root->val;
        if( target == 0 ){
            if( m.count({root,parent}) == 1 ){
                return;
            }
            m.insert({root,parent});
            ++ans;
        }        
        
        noOfPaths( root->left , target , parent );
        noOfPaths( root->right , target , parent);
        
    }
    
    void dfs ( TreeNode *root , int target ){
        
        if( root == NULL ){
            return;
        }
        
        noOfPaths( root , target , root);
        
        dfs( root->left , target );
        dfs( root->right , target );
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        ans = 0;
        dfs( root , targetSum );
        return ans;
        
    }
};