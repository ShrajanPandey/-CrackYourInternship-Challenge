class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        map<int,int> m;
        m[0] = 1;
        
        int sum = 0, ans = 0;
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            sum += nums[i];
            int rem = (sum%k < 0 ? sum%k + k : sum%k);
            
            if( m.count(rem) ){
                ans += m[rem];
            }
            
            m[rem]++;
        }
        
        return ans;
        
    }
};