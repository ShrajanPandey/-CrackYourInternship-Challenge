class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int row = matrix.size() , col = matrix[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >pq;
        
        for( int i = 0 ; i < matrix.size() ; ++i ){
            pq.push({matrix[i][0],{i,0}});
        }
        
        pair<int,pair<int,int>> cur;
        
        while( k-- ){
            
            cur = pq.top();
            pq.pop();
            
            int x = cur.second.first;
            int y = cur.second.second;
            
            if( y+1 < col ){
                pq.push({matrix[x][y+1],{x,y+1}});
            }
            
        }
        
        return cur.first;
        
    }
};