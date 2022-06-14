class Solution {
public:
    
    int dp[501][501];
    int ans( string &word1 , string &word2 , int i , int j){
        
        if( i == word1.length() && j == word2.length() ){
            return 0;
        }
        
        if( dp[i][j] != -1 ){
            return dp[i][j];    
        }
        
        if( i < word1.length() && j < word2.length() ){
            
            if( word1[i] != word2[j] ){
                return dp[i][j] = 1+min(ans(word1 , word2 , i+1 , j ),ans(word1 , word2 , i , j+1 ));
            }
            else{
                return dp[i][j] = ans(word1 , word2 , i+1 , j+1);
            }
            
        }
        else if( i < word1.length()){
            return dp[i][j] = word1.length()-i;
        }

        return dp[i][j] = word2.length()-j;
        
    }
    
    map<pair<int,int>,int> m;
    int minDistance(string &word1 , string &word2, int i = 0 , int j = 0 ){
        
        memset(dp , -1 , sizeof(dp));
        return ans(word1 , word2 , 0 , 0);
        
         if( i == word1.length() && j == word2.length() ){
            return 0;
        }
        
        if( m.count({i,j}) ){
            return m[{i,j}];
        }
        
        if( i < word1.length() && j < word2.length() ){
            if( word1[i] != word2[j] ){
                return m[{i,j}] = 1+min(minDistance(word1 , word2 , i+1 , j ),minDistance(word1 , word2 , i , j+1 ));
            }
            else{
                return m[{i,j}] = minDistance(word1 , word2 , i+1 , j+1);
            }
        }
        else if( i < word1.length()){
            return m[{i,j}] = word1.length()-i;
        }
        
        return m[{i,j}] = word2.length()-j;
        
        return 0;
        
       
    }
    
    //O(2n)
//     int minDistance(string word1 , string word2 ){
        
//         int n = word1.length() , m = word2.length();
//         int dp[m+1];
//         memset(dp , 0 , sizeof(dp));
        
//         for( int i = 0 ; i <= n ; ++i ){
//             int temp[m+1];
//             for( int j = 0 ; j <= m ; ++j ){
//                 if( i == 0 || j == 0 ){
//                     temp[j] = i+j;
//                 }
//                 else {
//                     temp[j] = word1[i-1] == word2[j-1] ? dp[j-1] : 1 + min(dp[j] , temp[j-1]);
//                 }
//             }
//             for(int i = 0 ; i <= m ; ++i ){
//                 dp[i] = temp[i];
//             }
//         }
        
//         return dp[m];
        
//     }
};