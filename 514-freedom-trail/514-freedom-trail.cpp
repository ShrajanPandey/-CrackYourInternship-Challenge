class Solution {
public:
    int n;
    
    int minSteps( string &ring , int top , string &key , int i , vector<vector<int>> &memo ){
        
        if( i >= key.length() ){
            return 0;
        }
        
        if( memo[top][i] != -1 ){
            return memo[top][i];
        }
        
        if( key[i] == ring[top] ){
            return memo[top][i] = 1 + minSteps( ring , top%n , key , i+1 , memo );
        }
        
        int j = top;
        int count = 0;
        
        while( ring[j] != key[i] ){
            ++j;
            j %= n;
            ++count;
        }
        
        int ans = 1 + count + minSteps( ring , j , key , i+1 , memo );
        
        int k = top;
        count = 0;
        
        while( ring[k] != key[i] ){
            --k;
            if( k < 0 ){
                k = n-1;
            }
            ++count;
        }
        
       
        ans = min( ans , 1 + count + minSteps( ring , k , key , i+1 , memo ) );
    
        return memo[top][i] = ans;
        
    }
    
    int findRotateSteps(string ring, string key) {
        
        vector<vector<int>> memo(ring.length()+1 , vector<int> (key.length()+1 , -1));
        n = ring.length();
        return minSteps( ring , 0 , key , 0 , memo );
        
    }
};