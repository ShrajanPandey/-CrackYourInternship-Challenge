class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        int c = 1;
        for( int i = 0 ; i < nums.size()-1 ; ++i ){
            if( nums[i+1] != nums[i] ){
                pq.push({c,nums[i]});
                if( pq.size() > k ){
                    pq.pop();
                }
                c = 1;
                continue;
            }
            ++c;
        }

        pq.push({c,nums[nums.size()-1]});
        if( pq.size() > k ){
            pq.pop();
        }

        vector<int> ans;
        while( pq.empty() != 1 ){
            
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        
        return ans;
        
        
    }
};