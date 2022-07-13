class Solution {
public:
    int mod = 1e9 + 7;
    int arr[100000][5];
    map<char,int> m;
    
    long long permutations( int n , char pre ){
        
        if( n == 0 ){
            return 1;
        }
        
        if( arr[n][m[pre]] != -1 ){
            return arr[n][m[pre]];
        }
      
        if( pre == 'a' ){
            return arr[n][m[pre]] = permutations( n -1 , 'e' )%mod;
        }
        if( pre == 'e' ){
            return arr[n][m[pre]] = (permutations( n-1 , 'a')%mod + permutations( n-1 , 'i' )%mod)%mod;
        }
        if( pre == 'i' ){
            return arr[n][m[pre]] = (permutations( n-1 , 'a')%mod + permutations( n-1 , 'e')%mod +  permutations( n-1 , 'o')%mod +  permutations( n-1 , 'u')%mod)%mod;
        }
        if( pre == 'o' ){
             return arr[n][m[pre]] = (permutations( n-1 , 'i')%mod +  permutations( n-1 , 'u')%mod)%mod;
        }
        if( pre == 'u' ){
            return arr[n][m[pre]] = permutations( n-1 , 'a')%mod;
        } 
        
        return 0;
        
    }
    
    int countVowelPermutation(int n) {
        
        memset( arr , -1 , sizeof(arr) );
        m['a'] = 0;
        m['e'] = 1;
        m['i'] = 2;
        m['o'] = 3;
        m['u'] = 4;
        
        return (permutations( n-1 , 'a')%mod + permutations( n-1 , 'e')%mod + permutations( n-1 , 'i')%mod + permutations( n-1 , 'o')%mod + permutations( n-1 , 'u')%mod)%mod;
        
    }
};