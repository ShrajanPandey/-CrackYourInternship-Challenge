class Solution {
public:
    vector<vector<int>> pal;
    
    bool isPal( string &s , int start , int end ){
        
        if( start >= end ){
            return true;
        }
        
        if( pal[start][end] != -1 ){
            return pal[start][end];
        }
        
        if( s[start] != s[end] ){
            return pal[start][end] = false;
        }
        
        return pal[start][end] = isPal( s , start+1 , end-1 );
        
    }
    
    int minCuts( string &s , int start , int end , vector<vector<int>> &memo ){
        
        if( start >= end || isPal( s , start , end ) ){
            return 0;
        }
        
        if( memo[start][end] != -1 ){
            return memo[start][end];
        }
        
        int ans = INT_MAX;
        for( int k = start ; k < end ; ++k ){
            if(isPal(s, start, k)){                         
                int temp = minCuts(s, k+1, end, memo) + 1;
                ans = min (ans, temp);
            }
        }
        
        return memo[start][end] = ans;
        
    }
    
    int minCut(string s) {
        
        pal.resize( s.length() , vector<int>(s.length() , -1));
        vector<vector<int>> memo(s.length(),vector<int> (s.length() , -1));
        return minCuts( s , 0 , s.length()-1 , memo );
        
    }
};