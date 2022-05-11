class Solution {
public:
    int dp[301][5002];
    
    int noofWays(int amount , vector<int> &coins, int l = 0 ){
        
        if( amount == 0 ){
            return 1;
        }    
           
        if( amount < 0 || l >= coins.size() ){
            return 0;
        }
        
        if( dp[l][amount] != -1 ){
            return dp[l][amount];
        }
     
        int ans = 0;
        for( int i = l ; i < coins.size() ; ++i ){
            // an.insert(coins[i]);/
            if( amount >= coins[i] )
            ans += noofWays(amount - coins[i], coins,i );
            // an.erase(lower_bound(an.begin(),an.end(),coins[i]));
        }
        
        return dp[l][amount] = ans;
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        memset(dp, -1 , sizeof(dp));
        return noofWays(amount , coins,0);
        
    }
    
};