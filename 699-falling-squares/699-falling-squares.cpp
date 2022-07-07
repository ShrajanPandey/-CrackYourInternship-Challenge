class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        
        vector<int> ans;
        
        vector<vector<int>> pos;
        int n = positions.size();
        
        for( int i = 0 ; i < n ;++i ){
            pos.push_back({positions[i][0],positions[i][0]+positions[i][1] ,positions[i][1]});
        }
        
    
        int maxH = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            
            int curH = pos[i][2],maxi = 0;
            
            for(int j = 0 ; j < i ; ++j ){
                
                if( !(pos[i][0] >= pos[j][1] || pos[i][1] <= pos[j][0]) ){
                    maxi = max( pos[j][2] , maxi );
                }
                
            }    
            
            curH += maxi;
            pos[i][2] = curH;
            
            maxH = max( maxH , curH);
            ans.push_back(maxH);
            
        }
        
        return ans;
        
    }
};