class Solution {
public:
    int n,m;
    bool isValid( int x , int y ){
    
        if( x < 0 || y < 0 || x >= n || y >= m ){
            return 0;
        }
        
        return 1;
    
    }
    
    int maxCherry( vector<vector<int>> &grid , int x , int y1 , int y2, vector<vector<vector<int>>> &memo){
         
        if( memo[x][y1][y2] != -1 ){
            return memo[x][y1][y2];
        }
        
        int cur = 0;
        
        if( y1 == y2 ){
            cur = grid[x][y1];
        }
        else{
            cur = grid[x][y1] + grid[x][y2];
        }
        
        if( x == n-1 ){
            return memo[x][y1][y2] = cur;   
        }

        
        int smallAns = 0;
        if( isValid(x+1,y1-1) ){
            
            if( isValid(x+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1-1 , y2-1, memo));
            }
            if( isValid(x+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1-1 ,  y2 , memo));
            }
            if( isValid(x+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1-1 , y2+1 , memo));
            }
            
        }
        if( isValid(x+1,y1) ){
            
            if( isValid(x+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1 , y2-1 , memo));
            }
            if( isValid(x+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1 , y2 , memo));
            }
            if( isValid(x+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1 , y2+1 , memo));
            }
            
        }
        if( isValid(x+1,y1+1) ){
            
            if( isValid(x+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1+1 , y2-1 , memo));
            }
            if( isValid(x+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1+1 , y2 , memo));
            }
            if( isValid(x+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x+1 , y1+1 , y2+1 , memo));
            }
            
        }
 
        return memo[x][y1][y2] = smallAns + cur;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> memo( n+1 , vector<vector<int>>( m+1 , vector<int>(m+1 , -1)));
        
        return maxCherry(grid , 0 ,0 , m-1 , memo);
        
    }
};