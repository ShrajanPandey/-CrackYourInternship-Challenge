class Solution {
public:
    int minSum(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp ){
        
        if( i == s1.length() && j == s2.length() ){
            return 0;
        }
        if( i == s1.length() ){
            int a = 0;
            while( j < s2.length() ){
                a += s2[j];
                ++j;
            }
            return a;
        }
        if( j == s2.length() ){
            int a = 0;
            while( i < s1.length() ){
                a += s1[i];
                ++i;
            }
            return a;
        }
        
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        
        if( s1[i] == s2[j] ){
            return dp[i][j] = minSum(s1 , s2 , i+1 , j+1 , dp);
        }
        
        return dp[i][j] = min(s1[i] + minSum(s1 , s2 , i+1 , j,dp) , s2[j] + minSum(s1 , s2 , i , j+1, dp));
        
    }
    
    int minimumDeleteSum(string &s1, string &s2) {
        
        vector<vector<int>> dp(s1.length()+1 , vector<int> (s2.length()+1 , -1 ));
        return minSum(s1 , s2 , 0 ,0 , dp);
        
    }
};