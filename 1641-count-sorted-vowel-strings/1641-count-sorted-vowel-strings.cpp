class Solution {
public:
    int countVowelStrings(int n, int l = 1 ) {
        
        vector<vector<int>> dp(5 ,vector<int>(n,0));
        for( int i = 0 ; i < n ; ++i ){
            dp[0][i] = 1;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 1; j < 5 ; ++j ){
                dp[j][i] = dp[j-1][i] + (i > 0 ? dp[j][i-1] : 1);
            }
        }
        
        return dp[4][n-1];
        
    }
};