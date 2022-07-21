class Solution {
public:
    int arr[2501][2501];
    
    int maxLen( vector<int> &nums , int pi , int i){
        
        if( i >= nums.size() ){
            return 0;
        }
        
        if( pi != -1 && arr[i][pi] != -1 ){
            return arr[i][pi];
        }
        
        int take = 0 , donttake = maxLen( nums , pi , i+1 );
        if( pi == -1 || nums[i] > nums[pi] ){
            take = 1 + maxLen( nums , i , i+1);
        }
        
        if( pi == -1 ){
            return max( take , donttake);
        }
        return arr[i][pi] = max( take , donttake);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(arr , -1 , sizeof(arr));
        return maxLen(nums ,-1 , 0 );
        
    }
};