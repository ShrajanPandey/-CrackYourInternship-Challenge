class Solution {
public:
    vector<vector<int>> ans;
    void generate(int si , vector<int> &nums , vector<int> subset){
        ans.push_back(subset);
        
        for( int i = si ; i < nums.size() ; ++i ){
            // generate(i+1 , nums , subset);
            if( i > si && nums[i] == nums[i-1] )continue;
            subset.push_back(nums[i]);
            generate(i+1 , nums , subset);
            subset.pop_back();
        }

    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        // vector<int> s;
        sort(nums.begin(),nums.end());
        generate(0 , nums , output);
        return ans;
    }
};