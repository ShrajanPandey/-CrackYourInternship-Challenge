class Solution {
public:
    int search(vector<int>& nums, int target) {
        
       int left = 0 , right = nums.size()-1;
        while( left < right ){
            int mid = left + ( right - left )/2;
            if( nums[mid] < nums[right] ){
                right = mid;
            }
            else{
                left = mid+1;
            }
            
        }
        
        int smallIdx = left;
        if( nums[smallIdx] == target ){
            return smallIdx;
        }
        left = 0 , right = nums.size()-1;
        if( target > nums[smallIdx] && nums[right] < target ){
            right = smallIdx;
        }
        else{
            left = smallIdx;
        }
        
        while( left <= right ){
            int mid = left + ( right - left )/2;
            if( nums[mid] == target ){
                return mid;
            }
            else if( nums[mid] > target ){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        return -1;
        
    }
};