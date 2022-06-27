// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    unordered_map<int,int> m;
    
    int minMoves( int n , int p ){
        
        if( p == n ){
            return 0;
        }
        if( p > n ){
            return 1000000;
        }
        if( m.count(p) ){
            return m[p];
        }    
        
        int a = minMoves(n , p+1);
        int b = minMoves( n , p*2);
        return m[p] = 1 + min(minMoves( n , p+1) , minMoves(n , p*2));
        
    }
    
    int minOperation(int n)
    {
        if( n == 1 ){
            return 1;
        }
        m.clear();
        return 1 + minMoves(n,1);
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
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends