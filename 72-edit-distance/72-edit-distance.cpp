class Solution {
public:
    int minMoves( string &word1, string &word2 , int i , int j , vector<vector<int>> &dp ){
        
        if( i >= word1.length() && j >= word2.length() ){
            return 0;
        }
        if( i >= word1.length() || j >= word2.length()){
            return max( word1.length() - i , word2.length() - j);
        }
         
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        
        if( word1[i] == word2[j] ){
            return dp[i][j] = minMoves(word1 , word2 , i+1 , j+1, dp );
        }
        
        int a = 1 + minMoves(word1 , word2 , i , j+1, dp);   
        int b = 1 + minMoves(word1, word2 , i+1 , j, dp);
        int c = 1 + minMoves(word1 , word2 , i+1 , j+1, dp);

        return dp[i][j] = min( a, min( b, c ));

    }
    
    int minDistance(string &word1, string &word2 ) {
        
        vector<vector<int>> dp(word1.length()+1 , vector<int> (word2.length()+1 , -1));
        return minMoves(word1 , word2 , 0 , 0 , dp);
        
    }
};