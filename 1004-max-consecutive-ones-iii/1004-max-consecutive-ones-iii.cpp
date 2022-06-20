class Solution {
public:
    //Space - O(k) ->at max k indices will be stored in queue 
    //Time - O(n) 
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0, j;
        for( j = 0 ; j < nums.size() ; ++j ){
            
            if( nums[j] == 0 ){
                --k;
            }
            if( k < 0 && nums[i++] == 0 ){
                ++k;
            }
            
        }
        
        return j-i;
        
    }
};