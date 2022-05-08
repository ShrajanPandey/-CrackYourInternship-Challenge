class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> isSeen(nums.size(),0);
        int ans = 0;
        for( auto i : nums ){
            int c = 0;
            while( isSeen[i] != 1 ){
                isSeen[i] = 1;
                i = nums[i];
                ++c;
            }
            ans = max( ans , c );
        }
        
        return ans;
        
    }
};