class Solution {
public:
    vector<vector<int>> ans;
    
    void solve( vector<int> &cnd , int target , int si , vector<int> smallAns ){
        
        if( target == 0 ){
            ans.push_back(smallAns);
            return;
        }
        // cout << si << " " << endl;
        if( si >= cnd.size() ){
            // cout << smallAns.size() << " M " << endl;
            // if( target == 0 )
            // ans.push_back(smallAns);   
            return;
        }   
        // for( int i = 0 ; i < smallAns.size() ; ++i ){
        //     cout << smallAns[i] << " N ";
        // }
        // cout << endl;
        
        for( int i = si ; i < cnd.size() ; ++i ){
            // cout << cnd[i] << " " << target << endl;
            if( cnd[i] <= target ){
                if( i > si && cnd[i] == cnd[i-1] ){
                    continue;
                }
                
                smallAns.push_back(cnd[i]);
                solve( cnd , target - cnd[i] , i+1 , smallAns);
                smallAns.pop_back();
            }
            else{
                break;
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        solve(candidates , target , 0 , vector<int>() );
        return ans;
        
    }
};