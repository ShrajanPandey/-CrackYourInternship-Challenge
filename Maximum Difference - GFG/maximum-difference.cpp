// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
        stack<int> stk;
        vector<int> pre( n , 0 );
        
        for( int i = 0 ; i < n ; ++i ){
            
            int cur = A[i];
            while( stk.empty() !=1 && stk.top() >= cur ){
                stk.pop();
            }
            
            if( stk.empty() ){
                pre[i] = 0;
            }
            else{
                pre[i] = stk.top();
            }
            stk.push(cur);
        }
        
        stack<int> st;
        int ans = INT_MIN;
        
        for( int i = n-1 ; i >= 0 ; --i ){
            
            int cur = A[i];
            while( st.empty() != 1 && st.top() >= cur ){
                st.pop();
            }
            
            if( st.empty() ){
                ans = max( ans , abs(pre[i]));
            }
            else{
                ans = max( ans , abs(pre[i]-st.top()));
            }
            st.push(cur);
            
        }
        
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
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends