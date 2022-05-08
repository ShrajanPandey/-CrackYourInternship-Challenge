// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        int n = N-1;
        
        while( N ){
            ans.push_back(N%10);
            N /= 10;
        }
        
        int carry = 0;
        while( n ){
            
            int size = ans.size();
            for( int i = 0 ; i < size ; ++i ){
                int pro = ans[i]*n;
                // cout << pro << " " << carry << endl;
                ans[i] = (pro + carry)%10;
                carry = (pro + carry)/10;
            }
            
            while( carry ){
                ans.push_back(carry%10);
                carry /= 10;
            }
            n--;
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends