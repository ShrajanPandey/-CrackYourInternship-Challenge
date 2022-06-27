// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int mod = 1e9 + 7;
    int arr[10001];
    
    int ways( int n ){
        
        if( n < 0 ){
            return 0;
        }    
        if( n == 0 ){
            return 1;
        }
        
        if( arr[n] != -1 ){
            return arr[n];  
        }
        
        return arr[n] = ((long long)(ways(n-1)%mod + ways(n-2))%mod)%mod;
        
    }
    
    int countWays(int n)
    {
        // memset(arr , -1 , sizeof(arr));
        // return ways(n);
        if( n <= 1 )
            return 1;
            
        int a = 1 , b = 2, temp ;
        for( int i = 2 ; i < n ; ++i ){
            temp =(a+b)%mod;
            a = b;
            b = temp;
        }
        
        return b;
        
    }
    
    
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends