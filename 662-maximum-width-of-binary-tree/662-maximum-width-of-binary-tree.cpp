class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if( root == NULL ){
            return 0;
        }
        
        unsigned int ans = 0;
        queue<TreeNode *> pend;
        map<TreeNode *,unsigned int> m;
        m[root] = 1;
        pend.push(root);
        
        unsigned int cur = 0 , maxWidth = 0;
        
        while( pend.size() != 0 ){
            
            int size = pend.size();
            unsigned int start = -1, end = -1;
            
            for( int i = 0 ; i < size ; ++i ){
                
                TreeNode* curNode = pend.front();
                pend.pop();
                
                if( start == -1 ){
                    start = m[curNode];
                    end = start;
                }
                unsigned int idx = m[curNode];
                end = idx;
                
                if( curNode->left ){
                    pend.push(curNode->left);
                    m[curNode->left] = 2*idx;
                }
                if( curNode->right ){
                    pend.push(curNode->right);
                    m[curNode->right] = 2*idx + 1;
                }
                
            }
            
            maxWidth = max( maxWidth , end-start+1 );
            
        }
        
        return maxWidth;
        
    }
};