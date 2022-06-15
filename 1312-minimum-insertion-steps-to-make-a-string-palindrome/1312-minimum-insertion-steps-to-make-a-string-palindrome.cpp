class Solution {
public:
    vector<vector<int>> memo;
    int minMoves( string &s , int i , int j ){
    
        if( i >= j ){
            return 0;
        }
        
        if( memo[i][j] != -1 ){
            return memo[i][j];
        }
        
        if( s[i] == s[j] ){
            return memo[i][j] = minMoves( s , i+1 , j-1 );
        }
        
        return memo[i][j] = 1 + min( minMoves( s , i+1 , j ) , minMoves( s , i , j-1 ) );
        
    }
    
    int minInsertions(string s) {
        
        memo.resize(s.length()+1 , vector<int> (s.length()+1 , -1));
        return minMoves( s , 0 , s.length()-1);
        
    }
};