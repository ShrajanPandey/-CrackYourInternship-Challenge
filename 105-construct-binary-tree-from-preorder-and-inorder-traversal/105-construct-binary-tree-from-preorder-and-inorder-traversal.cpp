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
    TreeNode *tree( vector<int> &pre , int pst , int pend , vector<int> &in , int inst , int inend , map<int,int> &m ){
        
        if( pst > pend || inst > inend ){
            return NULL;
        }
        
        TreeNode *root = new TreeNode(pre[pst]);
        int inRoot = m[pre[pst]];
        int noLeft = inRoot-inst;
        
        root->left = tree( pre , pst+1 , pst + noLeft , in , inst , inRoot-1 , m);
        root->right = tree( pre , pst+noLeft+1 , pend , in , inRoot+1 , inend , m );
        
        return root;
        
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> m;
        for( int i = 0 ; i < inorder.size() ; ++i ){
            m[inorder[i]] = i;
        }
        
        return tree( preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , m );
        
    }
};