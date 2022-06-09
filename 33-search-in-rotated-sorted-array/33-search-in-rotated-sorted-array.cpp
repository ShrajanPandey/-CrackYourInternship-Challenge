class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size(), left = 0 , right = n-1;
        
        while( left <= right ){
            
            int mid = left + ( right - left )/2;
            
            if( nums[mid] == target ){
                return mid;
            }
            
            if( nums[left] <= nums[mid] ){
                if( nums[left] <= target && nums[mid] > target ){
                    right = mid-1;
                }
                else{
                    left= mid+1;
                }
            }
            else{
                if( nums[right] >= target && nums[mid] < target ){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        
//         int n = nums.size();
//         int left = 0 , right = nums.size()-1;
//         while( left < right ){
//             int mid = left + ( right - left )/2;
//             if( nums[mid] < nums[right] ){
//                 right = mid;
//             }
//             else{
//                 left = mid+1;
//             }   
//         }
//         //we found smalles element hence its index equals the degree of rotation 
//         // we assume array to be a larger array and hence calcaulate index as per %n
//         int rot = left;
//         left = 0 , right = nums.size()-1;
        
//         while( left <= right ){
            
//             int mid = left + ( right - left )/2;
//             int realMid = (mid + rot)%n;
            
//             if( nums[realMid] == target ){
//                 return realMid;
//             }
//             else if( nums[realMid] > target ){
//                 right = mid-1;
//             }
//             else{
//                 left = mid+1;
//             }
            
//         }
        
        return -1;
        
//         int smallIdx = left;
//         if( nums[smallIdx] == target ){
//             return smallIdx;
//         }
//         left = 0 , right = nums.size()-1;
//         if( target > nums[smallIdx] && nums[right] < target ){
//             right = smallIdx;
//         }
//         else{
//             left = smallIdx;
//         }
        
//         while( left <= right ){
//             int mid = left + ( right - left )/2;
//             if( nums[mid] == target ){
//                 return mid;
//             }
//             else if( nums[mid] > target ){
//                 right = mid-1;
//             }
//             else{
//                 left = mid+1;
//             }
//         }
        
//         return -1;
        
    }
};