class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int p = INT_MIN;
        int o = 0;
        for( int i = 0 ; i < nums.size() ; ++i ){

            if( nums[i] < p ){
                if( o ){
                    ++o;
                    break;
                }
                ++o;
            }
            else{
                p = nums[i];
            }
        }

        if( o <= 1 ){
            return 1;
        }
        
        o = 0;
        p = INT_MAX;
        for( int j = nums.size()-1 ; j >= 0 ; --j ){
            
            if(nums[j] > p){
                if( o ){
                    return 0;
                }  
                ++o;
            }
            else{
                p = nums[j];
            }
            
        }
        
        return true;
        
    }
};