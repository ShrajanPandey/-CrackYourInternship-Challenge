class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for( int i = 0 ; i < strs.size() ; ++i ){
            int ones = 0;
            int zeros = 0;
            for( int j = 0 ; j < strs[i].length() ; ++j ){
                if( strs[i][j] == '0'){
                    ++zeros;
                }
                else{
                    ++ones;
                }
            }
            
            for( int j = m ; j >= zeros ; --j ){
                for( int k = n ; k >= ones ; --k ){
                    dp[j][k] = max(dp[j][k] , 1 + dp[j-zeros][k-ones]);
                }
            }
            
        }
        
        return dp[m][n];
        
    }
    
 
};