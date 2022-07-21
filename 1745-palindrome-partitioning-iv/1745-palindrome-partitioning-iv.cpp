class Solution {
public:
    vector<vector<int>> pal;
    int memo[2001][2001][4];
    
    bool isPal( string &s , int i , int j ){
        
        if( i >= j ){
            return true;
        }
        
        if( pal[i][j] != -1 ){
            return pal[i][j];
        }
        
        return pal[i][j] = ( (s[i] == s[j]) && isPal(s , i+1 , j-1) );
        
    }
    
    bool check( string &s , int i , int j , int k ){
        
        if( i >= j ){
            k -= (i == j);
            return k == 0;
        }
        if( k < 0 ){
            return false;
        }
        
        if( k == 1 ){
            return isPal( s , i , j );
        }
        
        if( memo[i][j][k] != -1 ){
            return memo[i][j][k];
        }
        
        for( int l = i ; l < j ; ++l ){
            
            if( isPal( s , i , l ) ){
                if( check( s , l+1 , j , k-1 ) ){
                    return true;
                }
            }
            
        }
        
        return memo[i][j][k] = false;
        
    }
    
    bool checkPartitioning(string s) {
        
        memset( memo , -1 , sizeof(memo) );
        pal.resize(s.length() , vector<int>(s.length() , -1));
        return check( s , 0 , s.length()-1 , 3 );
        
    }
};