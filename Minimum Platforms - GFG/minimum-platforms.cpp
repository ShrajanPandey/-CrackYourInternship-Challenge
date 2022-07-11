// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	int ans = 0;
    	vector<pair<int,int>> schedule;
    	
    	for( int i = 0 ; i < n ; ++i ){
    	    schedule.push_back({arr[i],0});
    	    schedule.push_back({dep[i],1});
    	}
    	
    	sort(schedule.begin(),schedule.end());
    	
    	int count = 0;
    	for( int i = 0 ; i < schedule.size() ; ++i ){
    	    if( schedule[i].second == 0 ){
    	        ++count;
    	    }
    	    else{
    	        --count;
    	    }
    	    ans = max( count , ans );
    	}
    
    	return ans;
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends