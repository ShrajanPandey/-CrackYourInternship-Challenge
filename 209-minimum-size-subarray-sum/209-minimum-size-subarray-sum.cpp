class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0 , j = 0 , ans = INT_MAX;
        int sum = 0;
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            
            sum += nums[i];
            
            if( sum >= target ){
    
                ans = min( ans , i - j + 1 );
                
                while( j < i && sum >= target ){
                    sum -= nums[j];
                     ++j;
                    if( sum >= target ){
                        ans = min(ans , i - j + 1 );
                    }
                }
                
            }
        }
        
        return (ans == INT_MAX ? 0 : ans);
        
    }
};