class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0] , end = intervals[0][1];
        
        for( int i = 0 ; i < intervals.size() ; ++i ){
            if( intervals[i][0] > end ){
                vector<int> a = {start,end};
                ans.push_back(a);
                end = intervals[i][1];
                start = intervals[i][0];
            }
            else{
                end = max(end,intervals[i][1]);
            }
        }
        
        vector<int> a = {start,end};
        ans.push_back(a);
        
        return ans;
        
    }
};