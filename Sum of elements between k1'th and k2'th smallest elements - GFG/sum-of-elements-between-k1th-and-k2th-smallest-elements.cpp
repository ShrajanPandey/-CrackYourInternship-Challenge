// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long,vector<long long> , greater<long long>> pq;
        
        for( int i = 0 ; i < N ; ++i ){
            
            pq.push(A[i]);
            
        }
        
        long long ans = 0;
        long long i = 1;
        
        while( pq.empty() != 1 ){
            
            if( i > K1 && i < K2 ){
                ans += pq.top();
            }
            pq.pop();
            ++i;
            
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends