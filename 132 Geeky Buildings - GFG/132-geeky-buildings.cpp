// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int nums[], int n){
		  int s3 = INT_MIN;
        stack<int> st;
        for( int i = n-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
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
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends