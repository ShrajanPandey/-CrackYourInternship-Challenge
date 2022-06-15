class Solution {
public:
    int maxLength = 0, x = 0;
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
        
        // memset(memo , -1 , sizeof(memo));
        // int xIdx = 0 , maxLen = 0;
        if( s.length() < 2 ){
            return s;
        }
        
        for( int i = 0 ; i < s.length()-1 ; ++i ){
            extendPal(s , i , i );//odd length palindrome
            extendPal(s , i , i+1);//even length palindrome
        }
        
        
        return s.substr(x , maxLength);
        
    }
    
    void extendPal(string &s , int i , int j ){
        
        while( i >= 0 && j < s.length() && s[i] == s[j] ){
            --i;
            ++j;
        }
        
        if( j - i - 1 > maxLength ){
            maxLength = j-i-1;
            x = i+1;    
        }
        
    }
    
};