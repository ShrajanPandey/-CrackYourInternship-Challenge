class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k ,int n , int l , vector<int> a ){
        
         if( n == 0 && k == 0 ){
            ans.push_back(a);
            return ;
        }
        
        if( n <= 0 ){
            return;
        }
        
        for( int i = l+1 ; i < 10 ; ++i ){
            if( n >= i ){
                a.push_back(i);
                solve(k-1 , n-i , i,a);
                a.pop_back();
            }
            else{
                break;
            }
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        solve(k , n , 0 , vector<int>());   
        return ans;
        
    }
};