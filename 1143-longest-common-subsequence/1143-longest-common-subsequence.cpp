class Solution {
public:
    
    int maxCommon(string &text1 , string &text2 , int i , int j, vector<vector<int>> &dp){
        
        if( i == text1.length() || j == text2.length() ){
            return 0;
        }
        
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        if( text1[i] == text2[j] ){
            return dp[i][j] = 1 + maxCommon(text1 , text2 , i+1 , j+1 ,dp);
        }
        
        return dp[i][j] = max(maxCommon(text1 , text2 , i+1 , j ,dp ) ,maxCommon(text1 , text2 , i , j+1, dp));
        
    }
    
    int longestCommonSubsequence(string text1 , string text2 ){
        
        vector<vector<int>> dp(text1.length()+1 ,vector<int> (text2.length()+1 , -1));
        return maxCommon(text1 , text2, 0 , 0, dp);
        
    }
};