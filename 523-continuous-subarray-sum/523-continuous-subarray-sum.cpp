class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if( nums.size() <= 1 ){
            return false;
        }
        
        map<int,int> m;
        m[0] = -1;
    
        int sum = 0;
        for( int i = 0 ; i < nums.size() ; ++i ){
            sum += nums[i];
            if( m.count(sum%k) && (i - m[sum%k] >= 2) ){
                return true;
            }
            
            if( m.count(sum%k) == 0 ){
                m[sum%k] = i;
            }
        }
        
        return false;
        
    }
};