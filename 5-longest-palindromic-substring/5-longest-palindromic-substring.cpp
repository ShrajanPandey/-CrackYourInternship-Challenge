class Solution {
public:
    int memo[1001][1001];
    bool isPal( string &s , int start , int end ){
        
        if( start >= end ){
            return 1;
        }
        
        if( memo[start][end] != -1 ){
            return memo[start][end];
        }
        
        if( s[start] != s[end] ){
            return 0;
        }
        
        return memo[start][end] = isPal(s , start+1 , end-1 );
        
    }
    
    string longestPalindrome(string s) {
        
        memset(memo , -1 , sizeof(memo));
        int xIdx = 0 , yIdx = 0, maxLen = 0;
        
        for( int i = 0 ; i < s.length() ; ++i ){
            
            for(int j = i ; j < s.length() ; ++j ){
                
                if( isPal(s , i , j ) ){
                    
                    if( j-i+1 > maxLen ){
                        maxLen = j-i+1;
                        xIdx = i;
                        yIdx = j;
                    }
                    
                }
                
            }
            
        }

        return s.substr(xIdx , maxLen);
        
    }
};