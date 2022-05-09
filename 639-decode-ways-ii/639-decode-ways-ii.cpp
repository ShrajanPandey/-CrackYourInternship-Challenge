class Solution {
public:
    int mod = 1e9+7;
    
    int numDecodings(string s) {
        
        if( s[0] == '0' ){
            return 0;
        }
        
        set<int> zeroIdx;
        for( int i = 0 ; i < s.length() ; ++i ){
            if( s[i] == '0' )
                zeroIdx.insert(i);
        }
        
        vector<long long> dp(s.length()+1,0);
        dp[0] = 1;
        
        if( s[0] == '*' ){
            if( zeroIdx.count(1) ){
                dp[1] = 2;
            }
            else{
                dp[1] = 9;
            }
        }
        else{
            dp[1] = 1;
        }
        
        for( int i = 2 ; i <= s.length() ; ++i ){

            if( s[i-1] == '*' ){
                if( zeroIdx.count(i) ){
                    dp[i] = (2*dp[i-1])%mod;
                    continue;
                }
                dp[i] = (9*dp[i-1])%mod;
                if( s[i-2] == '*' ){
                    dp[i] = (dp[i]%mod + (15*dp[i-2])%mod)%mod;
                }
                else if( s[i-2] == '1' ){
                    dp[i] = (dp[i]%mod + (9*dp[i-2])%mod)%mod;
                }
                else if( s[i-2] == '2' ){
                    dp[i] = (dp[i]%mod + (6*dp[i-2])%mod)%mod;
                }
            }
            else if( s[i-1] == '0' ){
                if( s[i-2] != '*'&& s[i-2] != '1' && s[i-2] != '2' ){
                    return 0;
                }
                dp[i] = dp[i-1]%mod;
            }
            else{
                if( zeroIdx.count(i) ){
                    dp[i] = dp[i-1]%mod;
                    continue;
                }
                dp[i] = dp[i-1]%mod;
    
                if( s[i-2] == '*' ){
                    if( s[i-1] < '7' ){
                        dp[i] += (2*dp[i-2])%mod;
                    }
                    else{
                        dp[i] = (dp[i] + dp[i-2])%mod;
                    }
                }
                else if( s[i-2] == '1' ){
                    dp[i] = (dp[i]%mod + dp[i-2]%mod)%mod;
                }
                else if( s[i-2] == '2' && s[i-1] < '7' ){
                    dp[i] = (dp[i]%mod + dp[i-2]%mod)%mod;
                }
            }
            // cout << dp[i-1] << " ";
        }
        // cout << dp[s.length()];
        // cout << endl;
        
        return dp[s.length()];
        
    }
};