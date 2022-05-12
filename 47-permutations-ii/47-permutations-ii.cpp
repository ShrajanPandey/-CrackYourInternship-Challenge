class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> p;
    map<int,int> m;
    
    vector<vector<int>> permute(vector<int> &nums , vector<bool> &used ){
        
        if( p.size() == nums.size() ){
            ans.push_back(p);
            return ans;
        }
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            if( i > 0 && nums[i] == nums[i-1] && used[i-1] == 0 ){
                continue;
            }
            if( used[i] == 0 ){
                p.push_back(nums[i]);
                used[i] = 1;
                permute(nums , used);
                used[i] = 0;
                p.pop_back();
            }
        }
        
        return ans;    
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums ) {
    
        vector<bool> used(nums.size(),0);
        
        sort(nums.begin(),nums.end());
        return permute(nums, used);
        
    }
};