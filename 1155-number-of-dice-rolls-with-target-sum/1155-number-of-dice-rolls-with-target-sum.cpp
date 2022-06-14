class Solution {
public:
    int mod = 1e9 + 7;
    
    long noWays( int n , int k , int target , vector<vector<long>> &memo){
        
        if( n == 0 ){
            if( target == 0 ){
                return 1;
            }
            return 0;
        }
            
        if( memo[n][target] != -1 ){
            return memo[n][target]%mod;
        }
        
        long ans = 0;
        for( int i = 1 ; i <= k ; ++i ){
            if( i > target ){
                break;
            }
            ans = (ans%mod + noWays( n-1 , k , target-i , memo)%mod)%mod;
        }
        
        return memo[n][target] = ans%mod;
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<long>> memo(n+1 , vector<long> ( target+1 , -1));
        return noWays( n , k , target, memo)%mod;
        
    }
};