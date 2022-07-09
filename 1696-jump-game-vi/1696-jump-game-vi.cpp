class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        vector<int> dp( nums.size() , INT_MIN);
        dp[0] = nums[0];
        
        multiset<int> pq;
        pq.insert(dp[0]);
        
        for( int i = 1 ; i < nums.size() ; ++i ){
                
            if( i > k ){
                pq.erase(pq.find(dp[i-k-1]));
            }
            dp[i] = *pq.rbegin() + nums[i];
            pq.insert(dp[i]);
            
        }
        
        return dp.back();
        
    }
};