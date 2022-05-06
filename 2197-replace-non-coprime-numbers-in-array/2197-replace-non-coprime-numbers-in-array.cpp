class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int i = 0 , n = nums.size();
        for( int j = 0 ; j < n ; ++j, ++i ){
            nums[i] = nums[j];
            if( i > 0 && __gcd(nums[i-1],nums[i]) > 1 ){
                int gcd = __gcd(nums[i-1],nums[i]);
                while( i > 0 && gcd > 1 ){
                    nums[i-1] = ((long long)nums[i]*(long long)nums[i-1])/gcd;
                    --i;
                    if( i > 0 ){
                        gcd = __gcd(nums[i-1],nums[i]);
                    }
                }
            }
        }
        
        vector<int> ans;
        for( int j = 0 ; j < i ; ++j ){
            ans.push_back(nums[j]);
        }
        
        return ans;
        
    }
};