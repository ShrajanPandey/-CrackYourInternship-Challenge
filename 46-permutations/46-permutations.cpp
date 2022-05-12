class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        if( p.size() == nums.size() ){
            ans.push_back(p);
            return ans;
        }
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            
            bool isp = 0;
            for( int j = 0 ; j < p.size() ; ++j ){
                if( p[j] == nums[i] ){
                    isp = 1;
                    break;
                }
            }
            
            if( isp == 0 ){
                p.push_back(nums[i]);
                permute(nums);
                p.pop_back();
            }
        }
        
        return ans;
        
    }
};