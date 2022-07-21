class Solution {
public:
    int arr[2502];
    
    int maxLen( vector<int> &nums , int pi , int i){
        
        if( i >= nums.size() ){
            return 0;
        }
        
        if( arr[pi+1] != -1 ){
            return arr[pi+1];
        }
        
        int take = 0 , donttake = maxLen( nums , pi , i+1 );
        if( pi == -1 || nums[i] > nums[pi] ){
            take = 1 + maxLen( nums , i , i+1);
        }
        
        return arr[pi+1] = max( take , donttake);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(arr , -1 , sizeof(arr));
        return maxLen(nums ,-1 , 0 );
        
    }
};