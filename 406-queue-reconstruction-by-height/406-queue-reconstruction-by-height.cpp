class Solution {
public:
    bool static cmp( vector<int> &a , vector<int> &b ){
        
        return a[0] > b[0] || ( a[0] == b[0] && a[1] < b[1] );
        
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),cmp);
        
        vector<vector<int>> ans;
        
        for( int i = 0 ; i < people.size() ; ++i ){
            ans.insert(ans.begin()+people[i][1] , people[i]);
        }
        
        return ans;
        
    }
};