class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int ans = INT_MAX;
        
        unordered_map<int,int> pre, suf;
        int n = nums.size();
        int sum = 0;
        pre[0] = 0;
        suf[0] = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            pre[sum] = i+1;
        }
        
        sum = 0;
        for( int j = n-1 ; j >= 0 ; --j ){
            sum += nums[j];
            int rem = x-sum;
            if( pre.count(rem) && pre[rem] < j+1 ){
                ans = min( ans , n-j + pre[rem]);
            }
            suf[sum] = n-j;
        }
        
        for( auto p = pre.begin() ; p != pre.end() ; ++p ){
            int rem = x - p->first;
            if( suf.count(rem) && suf[rem] < n-p->second ){
                ans = min(ans , p->second + suf[rem]);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
        
    }
};