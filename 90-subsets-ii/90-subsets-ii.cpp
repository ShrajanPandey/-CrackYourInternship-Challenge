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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> output;
        ans.push_back(output);
        sort(nums.begin() , nums.end());
        
        for( int i = 0 ; i < nums.size() ; ){
            
            int count = 0;//count of current element 
            while( i+count < nums.size() && nums[i] == nums[count+i] ){
                ++count;
            }
            
            int noSubsets = ans.size();
            for( int k = 0 ; k < noSubsets ; ++k ){
                vector<int> newSet = ans[k];
                for( int j = 0 ; j < count ; ++j ){
                    newSet.push_back(nums[i]);
                    ans.push_back(newSet);
                }
            }
            
            i += count;
            
        }
        
        return ans;
    }
};