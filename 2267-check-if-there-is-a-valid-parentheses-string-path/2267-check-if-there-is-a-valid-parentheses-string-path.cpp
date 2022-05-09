class Solution {
public:
   int mp[100][100][300];
    
    bool isPath(vector<vector<char>> &grid , int o, int n , int m , int x , int y ){

        if( x >= n || y >= m ){
            return false;
        }
        
        if( grid[x][y] == '(' ){
            ++o;
        }
        else{
            if( o > 0 ){
                --o;
            }
            else{
                return 0;
            }
        }
        
        if( x == n-1 && y == m-1 ){
            return o == 0;
        }
        
        if( mp[x][y][o] != -1 ){
            return mp[x][y][o];
        }
        
        bool a = 0 , b = 0;
        
        a = isPath(grid , o ,  n , m , x+1 , y );
        b = isPath(grid , o , n , m , x , y+1 );
        
        return mp[x][y][o] = a||b;
        
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        if( grid[0][0] == ')' || grid[n-1][m-1] == '(' ){
            return false;
        }
        
        // vector<vector<int>> v;
        memset(mp,-1,sizeof(mp));
        return isPath(grid , 0 , n , m , 0 , 0 );
        
    }
};