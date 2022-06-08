class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool isFirstCol = 0;
        int n = matrix.size() , m = matrix[0].size();
        
        bool a = 1 , b = 1;
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                if( matrix[i][j] == 0 ){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if( i == 0 ) a = 0;
                    if( j == 0 ) b = 0;
                }
                
            }
            
        }
        
        for( int i = 1 ; i < n ; ++i ){
            
            if( matrix[i][0] == 0 ){
                for( int j = 0 ; j < m ; ++j ){
                    matrix[i][j] = 0;
                }
            }
        
        }
        for( int j = 1 ; j < m ; ++j ){
            if( matrix[0][j] == 0 ){
                for( int i = 0 ; i < n ; ++i ){
                    matrix[i][j] = 0;
                }
            }
        }
        // cout << a << " "<< b<< endl;
        if( b == 0 ){
            for( int i = 0 ; i < n ; ++i ){
                matrix[i][0] = 0;
            }
        }
        if( a == 0 ){
            for( int j = 0 ; j < m ; ++j ){
                matrix[0][j] = 0;
            }
        }
        
    
        
    }
};