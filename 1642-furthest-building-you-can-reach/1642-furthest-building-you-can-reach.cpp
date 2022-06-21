class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int,vector<int> , greater<int>> pq;
        
        for( int i = 0 ; i < n-1 ; ++i ){
            
            int dif = heights[i+1] - heights[i];
            if( dif > 0 ){
                pq.push(dif);
            }
            if( pq.size() > ladders ){
                int minDif = pq.top();
                pq.pop();
                if( bricks < minDif ){
                    return i;
                }
                bricks -= minDif;
            }
            
        }
        
        return n-1;
        
    }
};