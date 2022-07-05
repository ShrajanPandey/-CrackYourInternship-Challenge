// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid( vector<vector<int>> &m , int i , int j ){
        if( i < 0 || j < 0 || i >= m.size() || j >= m.size() || m[i][j] == 0 ){
            return false;
        }
        return true;
    }
    
    void path(vector<vector<int>> &m , string s , int i , int j , vector<string> &ans){
            
        if( i >= m.size() || j >= m[0].size() || i < 0 || j < 0 ){
            return ;
        }
        
        if( m[i][j] == 0 ) {
            return;
        }
        
        if( i == m.size()-1 && j == m.size()-1 ){
            ans.push_back(s);
            return;
        }
        
        m[i][j] = 0;
        
        
        if( isValid(m , i-1 , j ) )
        path(m , s + 'U' , i-1 , j , ans);
        if( isValid(m , i+1 , j ) )
        path(m , s + 'D' , i+1 , j , ans);
        if( isValid( m , i , j-1) )
        path(m , s + 'L' , i , j-1 , ans);
        if( isValid( m , i , j+1 ) )
        path(m , s + 'R' , i , j+1 , ans);
        
        m[i][j] = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        vector<vector<int>> visited( n+1 , vector<int> ( n+1 , 9));
        path( m ,"", 0, 0 , ans);
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends