class Solution {
public:
    int n,m;
    bool isValid( int x , int y ){
    
        if( x < 0 || y < 0 || x >= n || y >= m ){
            return 0;
        }
        
        return 1;
    
    }
    
    int maxCherry( vector<vector<int>> &grid , int x1 , int y1 , int x2 , int y2, vector<vector<vector<vector<int>>>> &memo){
         
        if( memo[x1][y1][x2][y2] != -1 ){
            return memo[x1][y1][x2][y2];
        }
        
        int cur = 0;
        
        if( x1 == x2 && y1 == y2 ){
            cur = grid[x1][y1];
        }
        else{
            cur = grid[x1][y1] + grid[x2][y2];
        }
        
        if( x1 == n-1 && x2 == n-1 ){
            return memo[x1][y1][x2][y2] = cur;   
        }

        
        int smallAns = 0;
        if( isValid(x1+1,y1-1) ){
            
            if( isValid(x2+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1-1 , x2+1 , y2-1, memo));
            }
            if( isValid(x2+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1-1 , x2+1 , y2 , memo));
            }
            if( isValid(x2+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1-1 , x2+1 , y2+1 , memo));
            }
            
        }
        if( isValid(x1+1,y1) ){
            
            if( isValid(x2+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1 , x2+1 , y2-1 , memo));
            }
            if( isValid(x2+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1 , x2+1 , y2 , memo));
            }
            if( isValid(x2+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1 , x2+1 , y2+1 , memo));
            }
            
        }
        if( isValid(x1+1,y1+1) ){
            
            if( isValid(x2+1,y2-1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1+1 , x2+1 , y2-1 , memo));
            }
            if( isValid(x2+1,y2) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1+1 , x2+1 , y2 , memo));
            }
            if( isValid(x2+1,y2+1) ){
                smallAns = max( smallAns , maxCherry(grid , x1+1 , y1+1 , x2+1 , y2+1 , memo));
            }
            
        }
 
        return memo[x1][y1][x2][y2] = smallAns + cur;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<vector<int>>>> memo( n+1 , vector<vector<vector<int>>>( m+1 , vector<vector<int>>(n+1 , vector<int>(m+1 , -1))));
        
        return maxCherry(grid , 0 ,0, 0 , m-1 , memo);
        
    }
};