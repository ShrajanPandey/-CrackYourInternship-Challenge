class Solution {
public:
    int maxLen( vector<int> &nums , int si , int diff , int pre , vector<vector<int>> &memo){
        
        if( si >= nums.size() ){
            return 0;
        }    
            
        if( memo[diff][si] != -1 ){
            return memo[diff][si];
        }
        
        int ans = 0;
        for( int i = si ; i < nums.size() ; ++i ){
            
            if( nums[i]-pre == 0 ){
                continue;
            }
            if( diff == 0 ){
                ans = max( ans , 1+maxLen(nums , i+1 , (nums[i]-pre < 0 ? 2 : 1 ) ,nums[i], memo));
            }
            else if( diff == 1 && nums[i]-pre < 0 ){
                ans = max( ans , 1+maxLen(nums , i+1 , 2 , nums[i], memo));
            }
            else if( diff == 2 && nums[i]-pre > 0 ){
                ans = max( ans , 1+maxLen(nums , i+1 , 1 , nums[i], memo ));
            }
            
        }
        
        return memo[diff][si] = ans;
        
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<vector<int>> memo(3 , vector<int>(nums.size()+1 , -1));
        
        int ans = 0;
        for( int i = 0; i < nums.size() ; ++i ){
            
            ans = max( ans , 1+maxLen(nums , i+1 , 0 , nums[i] , memo));
            
        }
        
        return ans;
        
    }
};