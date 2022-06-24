// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        int posCeleb = 0, possibleIndx = -1;
        
        for( int i = 0 ; i < n ; ++i ){
            
            int allZero = 1;
            for( int j = 0 ; j < n ; ++j ){
                if( abs(m[i][j]) == 1 ){
    
                    if( abs(m[j][i]) == 1 ){
                        m[j][i] = -1;
                    }
                    else{
                        m[j][i] = 2;
                    }

                    allZero = 0;
                }
            }
            
            if( allZero ){
                possibleIndx = i;
                ++posCeleb;
                if( posCeleb > 1 ){
                    return -1;
                }
            }
            
        }
    
        if( possibleIndx == -1 ) {
            return -1;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            if( i != possibleIndx && m[possibleIndx][i] == 0 ){
                return -1;
            }
        }
        
        
        return possibleIndx;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends