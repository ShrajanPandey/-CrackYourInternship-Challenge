class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0;
        int start = 0 , end = 0;
        int n = nums.size(), count = 0;
        
        queue<int> zeroIdx;
        
        while( start < n && end < n ){
        
            if( nums[end] != 1 ){
                
                zeroIdx.push(end);
                if( count == k ){
                    
                    ans = max( ans , (end - start));
            
                    start = zeroIdx.front()+1;
                    zeroIdx.pop();
                    
                }   
                
                if( count != k )
                ++count;
                
            }
            
            // cout << start << " " << end << ' ' << ans << endl;
            ++end;
            
        }
        
        ans = max(ans , end - start);
        return ans;
        
    }
};