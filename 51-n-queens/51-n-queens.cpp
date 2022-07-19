class Solution {
public:
    vector<vector<string>> ans;
    
    bool isValid( vector<vector<int>> &pos , int x , int y ){
        
        for( int i = 0 ; i < pos.size() ; ++i ){
            if( pos[i][0] == x || pos[i][1] == y || abs(pos[i][0]-x) == abs(pos[i][1]-y) ){
                return false;
            } 
        }
        
        return true;
        
    }
    
    void allPos( int n , vector<vector<int>> &pos , int x , vector<string> &cur ){
        
        if( x == n ){
            ans.push_back(cur);
            return;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            if( isValid( pos , x , i ) ){
                
                pos.push_back({x,i});
                cur[x][i] = 'Q';
                allPos( n , pos , x+1, cur );
                cur[x][i] = '.';
                pos.pop_back();
                
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string p;
        for( int i = 0 ; i < n ; ++i ){
            p += '.';
        }
        
        vector<string> cur( n , p );
        vector<vector<int>> pos;
        allPos( n , pos , 0 , cur );
        
        return ans;
        
    }
};