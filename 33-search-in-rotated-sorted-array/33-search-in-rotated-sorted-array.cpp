class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int lo = 0 , hi = n-1;
        
        while( lo < hi ){
            int mid = (lo + hi)/2;
            if( nums[mid] > nums[hi] ){
                lo = mid+1;
            }    
            else{
                hi = mid; 
            }
        }
        
        int start = lo;
        int newStart = lo , newEnd = 0;
        if( nums[n-1] >= target && nums[lo] <= target ){
            newEnd = n-1;
            newStart = lo;
        }
        else{
            newEnd = lo-1;
            newStart = 0;
        }
        
        while( newStart <= newEnd ){
                
            int mid = (newStart + newEnd)/2;
            if( nums[mid] == target ){
                return mid;
            }
            else if( nums[mid] > target ){
                newEnd = mid-1;
            }
            else{
                newStart = mid+1;
            }
            
        }
        
        return -1;
        
    }
};