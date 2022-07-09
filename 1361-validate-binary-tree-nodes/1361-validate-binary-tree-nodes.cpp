class Solution {
public:
    int countNodes( vector<int> &left , vector<int> &right , int root ){
        
        if( root == -1 ){
            return 0;
        }
        
        return 1 + countNodes(left , right, left[root] ) + countNodes(left , right , right[root]);
        
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> inDegree(n , 0);
        
        for( int i = 0 ;i < n ; ++i ){
            if( leftChild[i] != -1 ){
                inDegree[leftChild[i]]++;
            }
            if( rightChild[i] != -1 ){
                inDegree[rightChild[i]]++;
            }
        }
        
        int root = -1;
        
        for(int i = 0 ; i < n ;++i ){
            if( inDegree[i] > 1 ){
                return false;
            }
            if( inDegree[i] == 0 ){
                if( root != -1 ){
                    return false;
                }
                root = i;
            }
        }
        
        if( root == -1 ){
            return false;
        }
        
        return countNodes( leftChild , rightChild , root ) == n ;
        
    }
};