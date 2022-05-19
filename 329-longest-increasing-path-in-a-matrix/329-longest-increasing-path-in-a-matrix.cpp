class Solution {
public:
    int n, m;
    int arr[205][205];
    
    int path(vector<vector<int>> &matrix , int i , int j , int prev ){

        if( i >= n || j >= m || i < 0 || j < 0 ){
            return 0;
        }
        
        if( prev == -1 ){
            prev = matrix[i][j];
        }
        else{
            if( matrix[i][j] <= prev ){
                return 0;
            }
        }
        
        if( arr[i][j] != -1 ){
            return arr[i][j];
        }
        
        prev = matrix[i][j];
        
        return arr[i][j] = 1 + max(path(matrix , i+1 , j , prev), max( path(matrix , i , j+1 , prev) , max(path(matrix, i-1 , j , prev) , path(matrix, i , j-1 , prev))));
                       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        n = matrix.size(), m = matrix[0].size();
        
        memset(arr , -1 , sizeof(arr));
        
        int ans = 0;
        for( int i = 0; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                ans = max( ans , path(matrix , i , j , -1 ));
                
            }
            
        }
        
        return ans;
        
    }
};