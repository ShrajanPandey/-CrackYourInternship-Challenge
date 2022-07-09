class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        vector<int> dp( nums.size() , INT_MIN);
        dp[0] = nums[0];
        
        deque<int> pq;
        pq.push_back(0);
        
        for( int i = 1 ; i < nums.size() ; ++i ){
                
            if( pq.front() < i-k ){
                pq.pop_front();
            }
            dp[i] = nums[i] + dp[pq.front()];
            while( pq.size() && dp[pq.back()] <= dp[i] ){
                pq.pop_back();
            }
            pq.push_back(i);
            
        }
        
        return dp.back();
        
    }
};