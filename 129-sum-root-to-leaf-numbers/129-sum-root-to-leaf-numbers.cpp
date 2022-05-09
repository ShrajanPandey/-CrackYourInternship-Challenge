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
    bool isLeaf( TreeNode *root ){
        return (root->left == NULL && root->right == NULL );        
    }
    
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> levelOrder;
        levelOrder.push({root,root->val});
        
        while( levelOrder.empty() != 1 ){
            
            int size = levelOrder.size();
            for( int i = 0 ; i < size ; ++i ){
                
                pair<TreeNode*,int> cur = levelOrder.front();
                levelOrder.pop();
                if( cur.first->left ){
                    levelOrder.push({cur.first->left , cur.second*10 + cur.first->left->val});
                }
                if( cur.first->right ){
                    levelOrder.push({cur.first->right , cur.second*10 + cur.first->right->val});
                }
                if( isLeaf(cur.first) ){
                    sum += cur.second;
                }
                
            }
            
        }
        
        return sum;
        
    }
};