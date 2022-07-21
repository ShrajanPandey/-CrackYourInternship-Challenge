class Solution {
public:
    int arr[601][101][101];
    int maxLen( vector<string> &strs , int m , int n , int i ){
        
        if( i >= strs.size()  ){
            return 0;
        }
        
        if( arr[i][m][n] != -1 ){
            return arr[i][m][n];
        }
        
        int z = 0 , o = 0;
        for( auto e : strs[i] ){
            if( e == '0' ){
                ++z;
            }
            else{
                ++o;
            }
        }
        
        int ans = 0;
        if( m-z >= 0 && n-o >= 0 ){
            ans = 1 + maxLen( strs , m-z , n-o , i+1);
        }
        
        ans = max( ans , maxLen( strs , m , n , i+1 ));
        return arr[i][m][n] = ans;
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(arr , -1 , sizeof(arr));
        return maxLen( strs , m , n , 0 );
        
    }
};