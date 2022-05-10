class Solution {
public:
    vector<vector<int>> ans;
    void generate(int si , vector<int> &nums , vector<int> subset){

        ans.push_back(subset);
        
        for( int i = si ; i < nums.size() ; ++i ){
            subset.push_back(nums[i]);
            generate(i+1 , nums , subset);
            subset.pop_back();
        }

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        // sort(nums.begin(),nums.end());
        generate(0 , nums , output);
        return ans;
    }
};