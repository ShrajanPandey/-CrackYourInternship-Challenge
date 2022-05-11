class Solution {
public:
    // int dp[2000];
    
//     int solve( vector<int>&nums , int target ){
        
//         if( target == 0 ){
//             return 1;
//         }
//         if( target < 0 ){
//             return 0;
//         }
        
//         if( dp[target] != -1 ){
//             return dp[target];
//         }
//         int ans = 0;
//         for( int i = 0 ; i < nums.size() ; ++i ){
//             if( target >= nums[i] )
//             ans += combinationSum4(nums , target-nums[i] );
//         }
        
//         return dp[target] = ans;
        
//     }
    
    int combinationSum4(vector<int>& nums, int target ) {
        
        unsigned int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        sort(nums.begin(),nums.end());
        
        for( int i = 1 ; i <= target ; ++i ){
            for( int j = 0 ; j < nums.size() ; ++j ){
                if( nums[j] > i ){
                    break;
                }
                dp[i] += dp[i-nums[j]];
            }
        }
        
        return dp[target];
        
    }
};