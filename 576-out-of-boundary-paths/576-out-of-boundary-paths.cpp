class Solution {
public:
    int mod = 1e9 + 7;
    int solve( int row , int col, int maxMov , int x , int y , vector<vector<vector<int>>> &dp){
        
        if( x < 0 || y < 0 || x >= row || y >= col ){
            return 1;
        }    
        
        if( maxMov == 0 ){
            return 0;
        }
        
        if( dp[maxMov][x][y] != -1 ){
            return dp[maxMov][x][y];
        }
        
        int ans = 0;
        ans = (ans%mod + solve(row , col ,maxMov-1 , x-1 , y , dp))%mod;
        ans = (ans%mod + solve(row , col ,maxMov-1 , x , y-1 , dp))%mod;
        ans = (ans%mod + solve(row , col ,maxMov-1 , x+1 , y , dp))%mod;
        ans = (ans%mod + solve(row , col ,maxMov-1 , x, y+1 , dp))%mod;
               
        return dp[maxMov][x][y] = ans%mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(maxMove+1 , vector<vector<int>> (m+1 , vector<int>( n+1 , -1)));
        
        return solve(m , n , maxMove , startRow , startColumn , dp);
        
    }
};