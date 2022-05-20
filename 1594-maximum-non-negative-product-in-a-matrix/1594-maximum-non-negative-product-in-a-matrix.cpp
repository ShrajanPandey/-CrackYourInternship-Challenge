// class Solution {
// public:
//     int mod = 1e9+7;
//     long long ans = INT_MIN;
    
//     void maxPath( vector<vector<int>> &grid , long long pro , int i , int j , int n , int m  ){
        
//         // pro = (pro*grid[i][j])%mod;
        
//         if( (i == n-1 && j == m-1) || pro == 0 ){
//             pro *= grid[i][j];
//             ans = max(ans , pro);
//             ans %= mod;
//             return;
//         }
        
//         if( i >= n || j >= m ){
//             return;
//         }
        
//         if( i < n-1 )
//         maxPath( grid , pro*grid[i][j] , i+1 , j , n , m);
//         if( j < m-1 )
//         maxPath( grid , pro*grid[i][j] , i , j+1 , n , m );
        
//     }
    
//     int maxProductPath(vector<vector<int>>& grid) {
        
//         int n = grid.size() , m = grid[0].size();
//         maxPath(grid , 1 , 0 , 0 , n , m );
//         // maxPath(grid , grid[0][0] , 0 ,1 );
        
//         if( ans < 0 ){
//             return -1;
//         }
        
//         return ans%mod;
        
//     }
// };
class Solution {
public:
    int mod = 1e9+7;
    long long ans = INT_MIN;
    
    void maxPath( vector<vector<int>> &grid , long long pro , int i , int j , int n , int m  ){
        
        // pro = (pro*grid[i][j])%mod;
        
        if( (i == n-1 && j == m-1) || pro == 0 ){
            pro *= grid[i][j];
            ans = max(ans , pro);
            // ans %= mod;
            return;
        }
        
        if( i >= n || j >= m ){
            return;
        }
        
        if( i < n-1 )
        maxPath( grid , pro*grid[i][j] , i+1 , j , n , m);
        if( j < m-1 )
        maxPath( grid , pro*grid[i][j] , i , j+1 , n , m );
        
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        maxPath(grid , 1 , 0 , 0 , n , m );
        // maxPath(grid , grid[0][0] , 0 ,1 );
        
        if( ans < 0 ){
            return -1;
        }
        
        return ans%mod;
        
    }
};
// long long int ans = -1e8; int mod=1e9+7
       
//     void solve(vector<vector<int>>& g,int n,int m,int i,int j,long long int res)
//     {
//         // base case
//        // if my res == 0 || i reached the n-1,m-1 pos calculate max of ans
//         if(res ==0||i == n-1 && j == m-1)
//         {
//             res = res * g[i][j];
//             ans = max(ans ,res);
//             return ;
//         }
//         if(i >=n || j >= m)return ;
//        //either go in i+1 ->->->
//         if(i < n-1)
//         solve(g,n,m,i+1,j,res*g[i][j]) ;
//        // either go in j+1 
//         if(j <  m-1)
//         solve(g,n,m,i,j+1,res*g[i][j]);
        
//     }
//     int maxProductPath(vector<vector<int>>& g) {
//         int n = g.size();
//         int m = g[0].size();
//         long long int res = 1;
//          solve(g,n,m,0,0,res);
//         if(ans < 0 )return -1;
//         return ans%mod;
//     }