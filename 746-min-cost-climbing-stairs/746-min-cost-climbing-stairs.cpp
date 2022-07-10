class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int a = 0 , b = cost[0],cur = 0;
        for( int i = 2 ; i < cost.size()+1 ; ++i ){
            cur = cost[i-1] + min(a, b);
            a = b;
            b = cur;
        }
        
        return min(a,b);
    }
};