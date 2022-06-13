class Solution {
public:
    map<pair<int,int>,int> mp;
    
    int minimumTotal(vector<vector<int>>& triangle , int n = 0, int i = 0) {
        
        if( i < 0 || n >= triangle.size() || i >= triangle[n].size()){
            return INT_MAX;
        }
        if( n == triangle.size()-1 ){
            return triangle[n][i];
        }
        
        if( mp.count(make_pair(n,i)) ){
            return mp[make_pair(n,i)];
        }
        
        int a = minimumTotal(triangle,n+1,i);
        int c = minimumTotal(triangle,n+1,i+1);
        
        return mp[make_pair(n,i)] = min(a,c) + triangle[n][i];
        
    }
};