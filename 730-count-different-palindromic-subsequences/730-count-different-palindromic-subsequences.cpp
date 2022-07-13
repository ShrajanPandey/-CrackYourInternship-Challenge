class Solution {
public:
    int mod = 1e9 + 7;
    int memo[1000][1000][5];
    
    long long noOfPal( string &s , int start , int end , int alpha ){
        
        if( start > end ){
            return 0;
        }
        
        if( start == end ){
            return s[start] == (char)(alpha + 'a');
        }
        
        if( memo[start][end][alpha] != -1 ){
            return memo[start][end][alpha];
        }
        
        int smallAns = 0;
        if( s[start] == s[end] && s[start] == (char)(alpha + 'a') ){
            smallAns = 2;
            for( int i = 0 ; i < 4 ; ++i ){
                smallAns = ( smallAns + noOfPal( s , start+1 , end-1 , i )%mod )%mod;
            }
        }
        else{
            smallAns = ( smallAns + noOfPal( s , start+1 , end, alpha )%mod )%mod;
            smallAns = ( smallAns + noOfPal( s , start , end-1, alpha )%mod )%mod;
            smallAns = ( smallAns - noOfPal( s , start+1 , end-1, alpha )%mod )%mod;
            if( smallAns < 0 ){
                smallAns += mod;
            }
        }
        
        return memo[start][end][alpha] = smallAns%mod;
        
    }
    
    int countPalindromicSubsequences(string s) {
        
        int ans = 0;
        memset(memo ,-1 , sizeof(memo));
        for( int i = 0 ; i < 4 ; ++i )
            ans = (ans + noOfPal( s , 0 , s.length()-1, i)%mod)%mod;
        
        return ans;
        
    }
};