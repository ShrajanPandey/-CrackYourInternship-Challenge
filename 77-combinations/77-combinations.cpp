class Solution {
public:
    void allCombinations(int start , int n , int k , vector<vector<int>> &ans , vector<int> &c){
        
        if( k == 0 ){
            ans.push_back(c);
            return;
        }
        
        if( start > n ){
            return;
        }

        c.push_back(start);
        allCombinations(start+1 , n , k-1 , ans , c);
        c.pop_back();
        allCombinations(start+1 , n , k , ans , c);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> c;
        allCombinations( 1 , n , k , ans , c);
        
        return ans;
        
    }
};