class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        map<int,int> m;
        int n = nums.size();
        
        int i = 0 , j = 0;
        while( j < k ){
            m[nums[j]]++;
            ++j;
        }
        
        auto p = m.end();
        --p;
        ans.push_back(p->first);
        
        while( i < n && j < n ){
            
            m[nums[i]]--;
            if( m[nums[i]] == 0 ){
                m.erase(nums[i]);
            }
            m[nums[j]]++;
            
            p = m.end();
            --p;
            ans.push_back(p->first);
            
            ++i;
            ++j;
            
        }
        
        return ans;
        
    }
};