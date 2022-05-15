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
    int deepestLeavesSum(TreeNode* root) {
        
        int ans = 0;
        queue<TreeNode *> p;
        p.push(root);
        
        while( p.size() ){
            
            ans = 0;
            int s = p.size();
            for( int i = 0 ; i < s ; ++i ){
                TreeNode *c = p.front();
                p.pop();
                if( c->left ){
                    p.push(c->left);
                }
                if( c->right ){
                    p.push(c->right);
                }
                if( c->left == NULL && c->right == NULL ){
                    ans += c->val;
                }
            }
         
        }
        
        return ans;
    }
};