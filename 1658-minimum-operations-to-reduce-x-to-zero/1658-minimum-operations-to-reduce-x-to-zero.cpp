class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int target = -x;
        target = accumulate(nums.begin(),nums.end(),target);
        cout << target << endl;
        
        if( target == 0 ){
            return nums.size();
        }
        
        unordered_map<int,int> pre;
        int n = nums.size();
        int sum = 0, ans = INT_MIN;
        pre[0] = -1;
        
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            if(pre.count(sum-target) ){
                ans = max( ans, i - pre[sum-target] );
            }
            pre[sum] = i;
        }
        
        return (ans == INT_MIN ? -1 : n - ans );
        
    }
};