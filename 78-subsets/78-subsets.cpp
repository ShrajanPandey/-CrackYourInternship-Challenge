class Solution {
public:
    vector<vector<int>> ans;
    void generate(int si , vector<int> &nums , vector<int> subset){
        if( si == nums.size() ){
            ans.push_back(subset);
            return;
        }
        
        generate(si+1 , nums , subset);
        subset.push_back(nums[si]);
        generate(si+1 , nums , subset);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        // set<vector<int>> s;
        generate(0 , nums , output);
        return ans;
    }
};