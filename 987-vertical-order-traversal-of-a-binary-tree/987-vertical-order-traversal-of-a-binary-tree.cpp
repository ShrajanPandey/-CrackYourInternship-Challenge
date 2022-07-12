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
    map<int,multiset<pair<int,int>>> trav;
    
    void ans( TreeNode *root , int x , int y ){
        
        if( root == NULL ){
            return;
        }
        
        ans(root->left , x - 1 , y + 1 );
        
        trav[x].insert({y,root->val});
        
        ans(root->right , x + 1 , y + 1 );
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        ans( root , 0 , 0 );
        vector<vector<int>> vertical;
        
        for( auto p = trav.begin() ; p != trav.end() ; ++p ){
            vector<int> cur;
            for(auto it = p->second.begin() ; it != p->second.end() ; ++it ){
                cur.push_back(it->second);
            }    
            vertical.push_back(cur);
        }
        
        return vertical;
        
    }
};