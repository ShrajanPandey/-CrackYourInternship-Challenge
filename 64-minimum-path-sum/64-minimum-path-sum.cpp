class Solution {
public:
       
    //Tc - O(n*m)
    //Sc - O(n*m)
    int dp[201][201];
    int n,m;
    
    int minPath( vector<vector<int>> &grid , int i , int j ){
        
        if( i >= n || j >= m ){
            return INT_MAX;
        }
        
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        
        if( i == n-1 && j == m-1 ){
            return grid[i][j];
        }
        
        return dp[i][j] = grid[i][j] + min( minPath(grid , i+1 , j ) , minPath(grid, i , j+1));
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return minPath(grid , 0 , 0);
            
    }
};