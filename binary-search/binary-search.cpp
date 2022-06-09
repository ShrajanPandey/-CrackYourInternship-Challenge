class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si = 0 , ei = nums.size()-1;
        while( si <= ei ){
            int mid = (si+ei)/2;
            if( nums[mid] > target ){
                --ei;
            }
            else if( nums[mid] < target ){
                ++si;
            }
            else{
                return mid;
            }
        }
        
        return -1;
        
    }
};