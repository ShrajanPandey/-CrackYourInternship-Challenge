class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       
        if( root == NULL ){
            return 0;
        }
        
        int ans = 0;
        queue<pair<TreeNode*,long long>> pending;
        pending.push({root,1});
        
        while( pending.empty() != 1 ){
            
            long long start = pending.front().second;
            long long end = pending.back().second;
            
            int size = pending.size();
            for( int i = 0 ; i < size ; ++i ){
                
                pair<TreeNode*,int> curPair = pending.front();
                pending.pop();
                
                TreeNode *curNode = curPair.first;
                
                if( curNode->left ){
                    pending.push({curNode->left,(long long)2*curPair.second + 1});
                }
                if( curNode->right ){
                    pending.push({curNode->right, (long long)2*curPair.second + 2});
                }
                
                ans = max((long long) ans , end - start+1 );
                
            }
            
        }
        
        return ans;
        
    }
};