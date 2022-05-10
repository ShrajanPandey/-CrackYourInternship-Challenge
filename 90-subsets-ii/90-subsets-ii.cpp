class Solution {
public:
    vector<vector<int>> ans;
//     void generate(int si , vector<int> &nums , vector<int> subset){
//         ans.push_back(subset);
        
//         for( int i = si ; i < nums.size() ; ++i ){
//             // generate(i+1 , nums , subset);
//             if( i > si && nums[i] == nums[i-1] )continue;
//             subset.push_back(nums[i]);
//             generate(i+1 , nums , subset);
//             subset.pop_back();
//         }

//     }
    //ITERATIVE 
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
//         vector<int> output;
//         ans.push_back(output);
//         sort(nums.begin() , nums.end());
        
//         for( int i = 0 ; i < nums.size() ; ){
            
//             int count = 0;//count of current element 
//             while( i+count < nums.size() && nums[i] == nums[count+i] ){
//                 ++count;
//             }
            
//             int noSubsets = ans.size();
//             for( int k = 0 ; k < noSubsets ; ++k ){
//                 vector<int> newSet = ans[k];
//                 for( int j = 0 ; j < count ; ++j ){
//                     newSet.push_back(nums[i]);
//                     ans.push_back(newSet);
//                 }
//             }
            
//             i += count;
            
//         }
        
//         return ans;
//     }
    
    void subsetsWithDup(vector<int>& nums, vector<int> res, vector<vector<int>>& ans, int start) {
        if (start == nums.size()) {
            ans.push_back(res);
            return;
        }
        subsetsWithDup(nums,res,ans,start+1);//do not take current 
        // include every duplicate in te every subset and as me move ahead without it we take others 
        // every possible subsets are counted.

        while (start + 1 < nums.size() && nums[start] == nums[start+1]) {
            res.push_back(nums[start]);
            ++start;
        }
        res.push_back(nums[start]);

        // include current if duplicate include every elements 
        subsetsWithDup(nums,res,ans,start+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subsetsWithDup(nums,res,ans,0);
        return ans;
    }
};