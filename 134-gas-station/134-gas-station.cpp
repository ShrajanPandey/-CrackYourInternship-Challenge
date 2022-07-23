class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int c = accumulate(cost.begin(),cost.end(), 0);
        int g = accumulate(gas.begin(),gas.end(), 0);
        
        if( g < c ){
            return -1;
        }
        
        int ct = 0;
        int ans = 0;
        for( int i = 0 ; i < gas.size() ; ++i ){
            ct += gas[i] - cost[i];
            if( ct < 0 ){
                ans = i+1;
                ct = 0;
            }
        }
        
        return ans;
        
    }
};