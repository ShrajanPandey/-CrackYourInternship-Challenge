class Solution {
public:
    int m[100000];
    int ans(vector<int> coins ,int amount ){
        if( amount == 0 ){
            return 0;
        }
        if( amount < 0 ){
            return INT_MAX;
        }
        
        if( m[amount] != -1 ){
            return m[amount];
        }
        
        int ans1 = INT_MAX;
        for( int i = 0 ; i < coins.size() ; ++i ){
            if( amount >= coins[i] ){
                int p = ans(coins , amount-coins[i]);
                ans1 = min(ans1 ,(p == INT_MAX ? p : p+1));
            }
        }
        // cout << amount << " " << ans1 << endl;
        return m[amount] = ans1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
//         memset(m , -1 , sizeof(m));
//         int a = ans( coins , amount );
        
//         return ( a == INT_MAX ? -1 : a );
        vector<int> dp(amount+1);
        dp[0] = 0;
        
        for( int i = 1; i < amount+1 ; ++i ){
            int ans = INT_MAX;
            for( int j = 0 ; j < coins.size() ; ++j ){
                if( coins[j] <= i ){
                    ans = min(ans , (dp[i-coins[j]] == INT_MAX ? dp[i-coins[j]] : dp[i-coins[j]]+1));
                }
            }
            dp[i] = ans;
        }
                              
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};