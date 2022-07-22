class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int minSub = nums.size();
        int sum = 0;
        for( int i = 0 ; i < nums.size() ; ++i ){
            sum = sum%p + nums[i]%p;
        }
        
        if( sum%p == 0 ){
            return 0;
        }
        
        int d = sum%p;
        map<int,int> m;
        int s = 0;
        m[0] = -1;
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            s = (s%p + nums[i]%p)%p;
            if( m.count((s-d+p)%p) ){
                minSub = min( minSub , i-m[(s-d+p)%p]);        
            }
            m[s%p] = i;
        }
        
        return (minSub < nums.size() ? minSub : -1);
        
    }
};