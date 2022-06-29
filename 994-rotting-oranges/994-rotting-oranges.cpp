class Solution {
public:
    int bfs( vector<vector<int>> &grid ){
        
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        queue<pair<int,int>> rottenOranges;
        int n = grid.size() , m = grid[0].size();
        
        for( int i = 0 ;i < n ; ++i ){

            for( int j = 0 ;j < m ; ++j ){
                if( grid[i][j] == 2 ){
                    rottenOranges.push({i,j});
                }
            }
            
        }
        
        int time = -1;
        
        while( rottenOranges.empty() != 1 ){
            
            int noOranges = rottenOranges.size();
            
            for( int i = 0 ; i < noOranges ; ++i ){
                
                pair<int,int> curOrange = rottenOranges.front();
                rottenOranges.pop();
                
                int x = curOrange.first;
                int y = curOrange.second;
                
                for( auto &cur : directions ){
                    
                    int x1 = x + cur[0];
                    int y1 = y + cur[1];
                    
                    if( x1 < 0 || y1 < 0 || x1 >= n || y1 >= m ){
                        continue;
                    }
                    
                    if( grid[x1][y1] == 1 ){
                        grid[x1][y1] = 2;
                        rottenOranges.push({x1,y1});    
                    }
                    
                }
                
            }

                ++time;
            
        }
        
        
        return time;
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int minTime = bfs(grid);
        
        for( int i = 0 ; i < grid.size() ; ++i ){
            for( int j = 0 ; j < grid[i].size() ; ++j ){
                if( grid[i][j] == 1 ){
                    return -1;
                }
            }
        }
        
        return minTime == -1 ? 0 : minTime ;
        
    }
};