class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    
    void permute(vector<int> nums , int si ){
        
        if( si >= nums.size() ){
            ans.push_back(nums);
            return ;
        }
        
        for(int i = si ; i < nums.size() ; ++i ){
            if( i != si && nums[si] == nums[i] ){
                continue;
            }
            swap(nums[i],nums[si]);
            permute(nums , si+1);
            // swap(nums[si], nums[i]);
        }
         
        return;
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums ) {
    
        // vector<bool> used(nums.size(),0);
        
        sort(nums.begin(),nums.end());
        permute(nums, 0);
        return ans;
        
    }
};