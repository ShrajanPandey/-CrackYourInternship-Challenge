class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size()-1;
        int idx = -1;
        
        for( int i = n ; i >= 0 ; --i ){
            
            if( i != 0 && nums[i-1] < nums[i] ){
                idx = i-1;
                break;
            }
            
        }
        
        if( idx == -1 ){
            sort(nums.begin(),nums.end());
            return;
        }
        
        sort(nums.begin()+idx+1 , nums.end());
        for( int i = idx + 1;  i < nums.size() ;++i ){
            if( nums[i] > nums[idx] ){
                swap(nums[idx] , nums[i]);
                return;
            }
        }
        
    }
};