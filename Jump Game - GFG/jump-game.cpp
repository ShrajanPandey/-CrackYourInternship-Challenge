// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int isPos(int A[] , int N , int i , vector<int> &arr ){
      
        if( i >= N-1 ){
            return 1;
        }

        if( arr[i] != -1 ){
            return arr[i];
        }
        
        int j = A[i];
        for( int p = 1 ; p <= j ; ++p ){
            if( isPos(A , N , i+p, arr) ){
                return 1;
            }
        }
        
        return arr[i] = 0;    
      
  }
  
    int canReach(int A[], int N ) {
        
        int lastReach = 0;
        for( int i = 0 ; i < N-1 ; ++i ){
            if( lastReach < i ){
                return 0;
            }
            lastReach = max( lastReach , i+A[i] );
        }
        
        if( lastReach >= N-1 ){
            return 1;
        }
        
        return 0;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends