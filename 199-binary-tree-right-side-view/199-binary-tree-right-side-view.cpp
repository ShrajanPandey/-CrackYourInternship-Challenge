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
    int maxi = INT_MIN;
    vector<int> ans;
    
    vector<int> rightSideView(TreeNode* root, int h = 0) {
        
        if( root == NULL ){
            return ans;
        }
        
        if( h > maxi ){
            ans.push_back(root->val);
        }
    
        maxi = max(maxi , h);
        rightSideView(root->right,h+1);
        rightSideView(root->left,h+1);
        
        return ans;
        
    }
};