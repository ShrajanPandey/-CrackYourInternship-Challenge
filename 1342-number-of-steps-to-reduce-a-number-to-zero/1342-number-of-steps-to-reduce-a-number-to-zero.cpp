class Solution {
public:
    int numberOfSteps(int num) {
        if( !num ){
            return 0;
        }
        
        int ans = 0;
        
        while( num ){
            ans += (num&1) ? 2 : 1;
            num >>= 1;
        }
        
        return ans-1;
    }
};