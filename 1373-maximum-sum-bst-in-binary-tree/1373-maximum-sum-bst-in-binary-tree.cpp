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
    class BSTNode{
        public:
        int maxVal;
        int minVal;
        bool isBST;
        int sum;
        
        BSTNode(){
            maxVal = INT_MIN;
            minVal = INT_MAX;
            isBST = 1;
            sum = 0;
        }
        
    };
    
    BSTNode SumBST(TreeNode *root, int &sum, int &maxSum){
        
        BSTNode ans;
        if( root == NULL ){
            return ans;
        }
        
        int newSum = 0;
        BSTNode left = SumBST(root->left, newSum, maxSum);
        BSTNode right = SumBST(root->right, newSum, maxSum);
        
        sum += root->val + newSum;
        newSum += root->val;
        
        if( left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val ){
            maxSum = max( maxSum , newSum);
            ans.isBST = 1;
        }
        else{
            ans.isBST = 0;
        }
        
        ans.maxVal = max({left.maxVal,right.maxVal,root->val});
        ans.minVal = min({left.minVal,right.minVal,root->val});
        ans.sum = sum;
        
        return ans;
        
    }
    
    int maxSumBST(TreeNode* root) {
        
        int sum = 0, maxSum = INT_MIN;
        BSTNode cur = SumBST(root , sum , maxSum);
        if( cur.isBST == 1 ){
            maxSum = max(maxSum , sum);
        }
        
        return max(0 , maxSum);
        
    }
};