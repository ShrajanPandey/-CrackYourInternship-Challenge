class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int,int> num;
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            num[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for( auto x = num.begin() ; x != num.end() ; ++x ){
            
            pq.push({x->second,x->first});
            if( pq.size() > k ){
                pq.pop();
            }
            
        }
        
        while( pq.empty() != 1 ){
            
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
            
        return ans;
        
    }
};