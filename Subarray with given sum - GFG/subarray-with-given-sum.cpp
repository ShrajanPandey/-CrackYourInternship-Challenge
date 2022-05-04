// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long sum = 0;
        int si = 0, ei = 0;
        for( ei = 0 ; ei < n ; ++ei ){
            sum += arr[ei];
            while( sum > s ){
                sum -= arr[si];
                ++si;
            }
    
            if( sum == s ){
                break;
            }
        }
        
        if( ei == n )--ei;
        while( si <= ei && sum != s ){
            sum -= arr[si];
            ++si;
        }
        if( sum != s )
            return vector<int> (1,-1);
        
        vector<int> ans = {si+1,ei+1};
        return ans;
        
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
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends