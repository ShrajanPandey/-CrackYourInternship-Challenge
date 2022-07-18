class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if( intervals.size() == 0 ){
            return {{}};
        }
        
        vector<vector<int>> ans;
    
        sort( intervals.begin() , intervals.end() );
        int lo = intervals[0][0] , hi = intervals[0][1];
        
        int i = 1, n = intervals.size();
        while( i < n ){
            
            if( hi < intervals[i][0] ){
                ans.push_back({lo,hi});
                lo = intervals[i][0];
                hi = intervals[i][1];
            }
            else{
                hi = max( hi , intervals[i][1]);
                lo = min( lo , intervals[i][0]);
            }
            ++i;
            
        }
        
        ans.push_back({lo,hi});
        return ans;
        
    }
};