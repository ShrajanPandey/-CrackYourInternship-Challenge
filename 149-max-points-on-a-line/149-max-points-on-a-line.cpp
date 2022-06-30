class Solution {
public:
    long double slope( vector<int> &a , vector<int> &b ){
        
        long double x = a[0] , y = a[1] ,x1 = b[0] , y1 = b[1];
        long double s = (y1-y)/(x1-x);
        return s;
        
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        int fans = 1;
        
        for( int i = 0 ; i < points.size() ; ++i ){
            
            int ans = 0;
            unordered_map<long double,int> slopes;
            
            for( int j = 0 ; j < points.size() ; ++j ){
                
                if( i == j ){
                    continue;
                }
                
                long double curSlope = slope(points[i],points[j]);
                slopes[curSlope]++;
                ans = max( ans , (int)slopes[curSlope]+1 );
                
            }
            
            fans = max( fans , ans);
        
        }
        
        return fans;
        
    }
};