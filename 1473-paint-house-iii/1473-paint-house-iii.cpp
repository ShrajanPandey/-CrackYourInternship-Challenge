class Solution {
public:
    
    int minPaintCost( vector<int> &houses ,vector<vector<int>> &costs, int n , int i , int target , int pre ,vector<vector<vector<int>>> &memo  ){
        
        if( i >= houses.size() ){
            if( target == 0 ){
                return 0;
            }    
            return INT_MAX;
        }   
        
        if( target < 0 ){
            return INT_MAX;
        }
        
        if( pre != -1 && memo[i][pre][target] != -1 ){
            return memo[i][pre][target];
        }
        
        if( houses[i] != 0 ){
            
            int ans = minPaintCost(houses , costs , n , i+1 , target-(pre != houses[i]) , houses[i], memo);    
            return memo[i][pre][target] = ans;
            
        }
        
        int ans = INT_MAX;
        for( int cur = 1 ; cur <= n ; ++cur ){
            
            int smallAns = minPaintCost(houses , costs, n ,i+1,target-(pre != cur) ,cur, memo);
            if( smallAns != INT_MAX ){
                ans = min( ans , smallAns + costs[i][cur-1] );
            }
            
        }
        
        return memo[i][pre][target] = ans;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
                
        vector<vector<vector<int>>> memo(m , vector<vector<int>>(n+1 , vector<int> (target+1 , -1)));
        int minPrice = minPaintCost(houses , cost , n , 0 , target , 0, memo);
        
        return (minPrice == INT_MAX ? -1 : minPrice);
        
    }
};