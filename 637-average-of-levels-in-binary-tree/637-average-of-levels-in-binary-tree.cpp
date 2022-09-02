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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        queue<TreeNode *> pq;
        pq.push(root);
        
        while( pq.size() ){
            
            double sum = 0;
            double size = pq.size();
            for( int i = 0 ;i < size ; ++i ){
                
                TreeNode *cur = pq.front();
                pq.pop();
                
                if( cur->left ){
                    pq.push(cur->left);
                }
                if( cur->right ){
                    pq.push(cur->right);
                }
                
                sum += cur->val;
                
            }
            
            ans.push_back((double)(sum/size));
            
        }
        
        return ans;
        
    }
};