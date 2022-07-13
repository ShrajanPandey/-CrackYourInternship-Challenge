class Solution {
public:
    int mod = 1e9+7;
    int countWays( int steps , int &arrLen , int cur , vector<vector<int>> &memo ){
        
        if( steps == 0 ){
            if( cur == 0 ){
                return 1;
            }
            return 0;
        }
            
        if( memo[cur][steps] != -1 ){
            return memo[cur][steps]%mod;
        }
        
        int a = 0 , b = 0 , c = 0;
        if( cur+ 1 < arrLen ){
            a = countWays( steps-1 , arrLen , cur+1 , memo )%mod;
        }
        if( cur-1 >= 0 ){
            b = countWays( steps-1 , arrLen, cur-1 , memo )%mod;
        }
        c = countWays( steps-1 , arrLen , cur , memo )%mod;
        
        return memo[cur][steps] = ((a+b)%mod+c)%mod;
            
    }
    
    int numWays(int steps, int arrLen) {
        
        vector<vector<int>> memo(steps+1 , vector<int> ( steps+1 , -1));
        return countWays( steps , arrLen , 0 , memo );
        
    }
};