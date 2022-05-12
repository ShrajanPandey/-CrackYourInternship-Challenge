class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    
    void solve(vector<int> &nums , int begin ){
        
        if( begin >= nums.size() ){
            ans.push_back(nums);
            return;
        }
        
        for(int i = begin ; i < nums.size() ; ++i ){
            swap(nums[begin],nums[i]);
            solve(nums , begin+1 );
            swap(nums[begin],nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
//         if( p.size() == nums.size() ){
//             ans.push_back(p);
//             return ans;
//         }
        
//         for( int i = 0 ; i < nums.size() ; ++i ){
            
//             bool isp = 0;
//             for( int j = 0 ; j < p.size() ; ++j ){
//                 if( p[j] == nums[i] ){
//                     isp = 1;
//                     break;
//                 }
//             }
            
//             if( isp == 0 ){
//                 p.push_back(nums[i]);
//                 permute(nums);
//                 p.pop_back();
//             }
//         }
        solve( nums , 0);
        
        return ans;
        
    }
};