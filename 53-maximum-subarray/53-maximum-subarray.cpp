class Solution {
public:
    int maxSubArray(vector<int>& nums,int i = 0,int ans = 0) {
        
        vector<int> dp( nums.size() , 0 );
        dp[0] = nums[0];
        int mx = nums[0];
        
        for( int i = 1 ; i < nums.size() ; ++i ){
            dp[i] = max( dp[i-1] + nums[i] , nums[i]);
            mx = max( dp[i] , mx);
        }
        
        return mx;

    }
};