// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		 
    	    queue<char> q;
    	    map<char,int> s;
            q.push(A[0]);
            s[A[0]] = 1;
        
    	    for( int i = 1 ; i < A.length() ; ++i ){
    	        if( q.size() != 0 && q.front() == A[i] ){
    	            q.pop();
    	           // cout << A[i] << endl;
    	            while( q.size() != 0 && s[q.front()] != 1 ){
    	               // cout << q.front() << " " << s[q.front()] << endl;
    	                q.pop();
    	            }
    	        }
    	        s[A[i]]++;
	            if( s[A[i]] == 1 ){
	               // cout << A[i] << endl;
	                q.push(A[i]);
	            }
	            if( q.size() ){
	                A[i] = q.front();
	            }
	            else{
	                A[i] = '#';
	            }
    
    	    }
		   
		    return A;
	
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends