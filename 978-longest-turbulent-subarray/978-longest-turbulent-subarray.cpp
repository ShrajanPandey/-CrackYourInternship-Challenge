class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 1));
        
        int ans = 1;
        
        for( int i = 1 ; i < n ; ++i ){
            
            if( nums[i-1] > nums[i] ){
                dp[0][i] += dp[1][i-1];
            }
            if( nums[i-1] < nums[i] ){
                dp[1][i] += dp[0][i-1];
            }
            
            ans = max( ans , max( dp[0][i] , dp[1][i] ));
            
        }
        
        return ans;
        
    }
};