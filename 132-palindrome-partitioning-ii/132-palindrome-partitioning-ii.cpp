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
    
    int minCuts( string &s , int start , vector<int> &memo ){
        
        if( start >= s.length()-1 || isPal( s , start , s.length()-1 ) ){
            return 0;
        }
        
        if( memo[start] != -1 ){
            return memo[start];
        }
        
        int ans = INT_MAX;
        for( int k = start ; k < s.length()-1 ; ++k ){
            
            if(isPal(s, start, k)){                         
                int temp = minCuts(s, k+1,memo) + 1;
                ans = min (ans, temp);
            }
            
        }
        
        return memo[start] = ans;
        
    }
    
    int minCut(string s) {
        
        pal.resize( s.length() , vector<int>(s.length() , -1));
        vector<int> memo(s.length() , -1);
        return minCuts( s , 0 , memo );
        
    }
};