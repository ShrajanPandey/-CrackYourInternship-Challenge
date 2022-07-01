class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v;
        
        map<int,int> m;
        for( int i = 0 ; i < nums.size() ; ++i ){
            // cout << nums[i] << ' ' << target-nums[i] << endl;
            if( m.count(target-nums[i]) ){
                return {i,m[target-nums[i]]};
            } 
            m[nums[i]] = i;
        }
        
        return {};
        
    }
};