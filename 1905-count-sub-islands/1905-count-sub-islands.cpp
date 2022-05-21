class Solution {
public:
    int n , m;
    vector<vector<int>> visited;
    
    bool subIsland(vector<vector<int>> &g1 , vector<vector<int>> &g2 , int i , int j ){
        
        if( i < 0 || j < 0 || i >= n || j >= m || g2[i][j] == 0 ){
            return 1;
        }    
        
        if( visited[i][j] == 1 ){
            return 1;
        }
        
        if( g1[i][j] == 0 ){
            return 0;
        }
        
        visited[i][j] = 1;
        
        return subIsland(g1 , g2 , i+1 , j) & subIsland(g1 , g2,i-1 , j) & subIsland(g1,g2 , i , j+1 ) & subIsland(g1 , g2 , i , j-1 );
        
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        n = grid1.size() , m = grid1[0].size();
        int ans = 0;
        
        visited.resize(n , vector<int>(m,0));
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                if( grid2[i][j] == 1 && visited[i][j] == 0 ){
                    
                    if( subIsland(grid1 , grid2, i , j ) ){
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};