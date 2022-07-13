class Solution {
public:
    int longestPal( string &s , int start , int end , vector<vector<int>> &memo ){
        
        if( start > end ){
            return 0;
        }
        
        if( start == end ){
            return 1;
        }
        
        if( memo[start][end] != -1 ){
            return memo[start][end];
        }
        
        if( s[start] == s[end] ){
            return memo[start][end] = 2 + longestPal( s , start+1 , end-1 , memo);
        }
        
        return memo[start][end] = max( longestPal( s , start +1 , end , memo ) , longestPal( s , start , end-1 , memo));
        
    }
    
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> memo( s.length() , vector<int>( s.length(), -1 ));
        return longestPal( s , 0 , s.length()-1 , memo );
    
    }
};