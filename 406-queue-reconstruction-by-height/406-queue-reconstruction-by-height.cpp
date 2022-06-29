class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end());
        
        vector<vector<int>> ans;
        
        int i = people.size()-1;
       
        while( i >= 0 ){
            
            int p = people[i][0];
            int j = i;
            
            while( i >= 0 && people[i][0] == p ){
                --i;
            }
            
            int k = i+1;
            
            while( k <= j ){
                ans.insert(ans.begin()+people[k][1],people[k]);
                ++k;
            }
            
        }
        
        return ans;
        
    }
};