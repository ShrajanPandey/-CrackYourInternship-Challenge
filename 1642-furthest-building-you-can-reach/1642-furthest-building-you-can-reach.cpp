class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int> pq;
        int sum = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            
            if( i != n-1 && heights[i+1] > heights[i] ){
                
                pq.push(abs(heights[i+1]-heights[i]));
                sum += abs(heights[i+1]-heights[i]);
                
                if( sum > bricks ){
                    sum -= pq.top();
                    if( ladders ){
                        --ladders;
                    }
                    else{
                        return i;
                    }
                    pq.pop();
                }
                
            }
            
        }
        
        return n-1;
        
    }
};