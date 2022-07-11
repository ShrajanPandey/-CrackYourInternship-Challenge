// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int maxSum( int *arr , int n , int i , int prev , vector<int> &memo){
	    
	    if( i >= n ){
	        return 0;
	    }    
	   
	   if(memo[i] != -1 ){
	       return memo[i];
	   }
	   
        int a = 0 , b = 0;
        a = maxSum(arr , n , i+2 , i , memo) + arr[i];
        b = maxSum( arr , n , i+1 , prev , memo);

	    return memo[i] = max( a , b );
	    
	}
	
	int findMaxSum(int *arr, int n) {
	    
	    vector<int> memo( n , - 1);
	    return maxSum( arr , n , 0 , -2 , memo );
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends