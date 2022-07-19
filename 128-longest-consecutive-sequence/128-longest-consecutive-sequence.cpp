class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s;
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            s.insert(nums[i]);
        }
        
        int p = INT_MIN;
        int ans = 0, count = 0;
        
        for( auto it : s ){
            if( p == INT_MIN ){
                count = 1;
                p = it;
                continue;
            }
            if( p + 1 == it ){
                p = it;
                ++count;
            }
            else{
                p = it;
                count = 1;
            }
            ans = max( ans , count);
        }
        
        ans = max( ans , count );
        return ans;
        
    }
};