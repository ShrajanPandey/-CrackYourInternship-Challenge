class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        vector<int> dp( nums.size() , INT_MIN);
        dp[0] = nums[0];
        
        priority_queue<pair<int,int>> pq;
        pq.push({dp[0],0});
        
        for( int i = 1 ; i < nums.size() ; ++i ){
                
            while( pq.size() && pq.top().second < i-k ){
                pq.pop();
            }
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i],i});
    
        }
        
        return dp[nums.size()-1];
        
    }
};