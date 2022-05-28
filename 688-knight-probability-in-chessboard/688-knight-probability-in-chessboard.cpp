class Solution {
public:
    
    vector<vector<int>> arr = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    
    double allPossibleMoves( int n , int moves , int row , int col , vector<vector<vector<double>>> &dp){
        
        if( row < 0 || col < 0 || row >= n || col >= n ){
            // ++total;
            return 0;
        }    
        
        if( moves == 0 ){
            return 1;
        }
        
        if( dp[row][col][moves] != INT_MAX ){
            return dp[row][col][moves];
        }
        
        double ans = 0;
        
        for( auto x : arr ){
            ans += 0.125*allPossibleMoves(n , moves-1 , row + x[0], col + x[1], dp);
        }
        
        return dp[row][col][moves] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp( 26 , vector<vector<double>> (26, vector<double> (101 , INT_MAX)));
        return allPossibleMoves( n , k , row , column , dp);
        
    }
};