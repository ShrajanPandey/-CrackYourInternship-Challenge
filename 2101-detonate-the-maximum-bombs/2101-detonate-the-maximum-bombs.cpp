class Solution {
public:
    bool isInRange(vector<int> &b1 , vector<int> &b2 ){
        
        long long x1 = b1[0] , y1 = b1[1] , r1 = b1[2];
        long long x2 = b2[0] , y2 = b2[1] , r2 = b2[2];
        
        return (long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2) <= (long long)r1*r1;
        
    }
    
    void dfs( map<int,vector<int>> &bombsInRange , vector<int> &visited , int cur ,int &no){
    
        ++no;
        visited[cur] = 1;

        for( auto i = bombsInRange[cur].begin() ; i != bombsInRange[cur].end() ; ++i ){
            
            if( visited[*i] == 0 ){
                dfs(bombsInRange , visited , *i , no);
            }
            
        }
        
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        map<int,vector<int>> bombsInRange;
        int n = bombs.size();
        int ans = 1;
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = i+1 ; j < n ; ++j ){
                
                if( isInRange(bombs[i] , bombs[j]) ){
                    bombsInRange[i].push_back(j);
                }
                if( isInRange(bombs[j], bombs[i]) ){
                    bombsInRange[j].push_back(i);
                }   
                
            }
            
        }
        
        
        for( int i = 0 ; i < n ; ++i ){
            
            vector<int> visited(n , 0);
            int noOfBombs = 0;
            dfs(bombsInRange , visited , i , noOfBombs);
            ans = max( ans , noOfBombs);
            
        }
        
        return ans;
        
    }
};