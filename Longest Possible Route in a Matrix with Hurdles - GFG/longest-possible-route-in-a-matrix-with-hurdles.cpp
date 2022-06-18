// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans = INT_MIN;
    vector<vector<int>> direc = {{-1,0},{0,-1},{1,0},{0,1}};
    
    void maxPath( vector<vector<int>> &matrix ,int xs , int ys , int xd , int yd , int cur , vector<vector<int>> &visited ){
    
        // cout << xs <<  " " << ys << endl;
        if( xs < 0 || ys < 0 || xs >= matrix.size() || ys >= matrix[0].size() || matrix[xs][ys] == 0 ){
            return ;
        }
        
        if( xs == xd && ys == yd ){
            ans = max( ans, cur );
            return;
        }    
        
        if(visited[xs][ys] == 1) {
            return;
        }
        
        visited[xs][ys] = 1;
        for( int i = 0 ; i < 4 ; ++i ){
            // cout << direc[i][0] << " " << direc[i][1] << endl;
            // cout << xs + direc[i][0] << " " << ys + direc[i][1] << endl;
            maxPath(matrix , xs + direc[i][0] , ys + direc[i][1] , xd , yd , cur + 1, visited );
        }
        visited[xs][ys] = 0;
    
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        ans = INT_MIN;
        vector<vector<int>> visited(matrix.size(), vector<int> (matrix[0].size(),0));
        maxPath(matrix , xs , ys , xd , yd , 0, visited);
        return ( ans == INT_MIN ? -1 : ans );
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends