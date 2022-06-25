// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    
    int arr[1101];
    
    bool isPossible( string &A , int i , unordered_set<string> &s ){
        
        if( i >= A.length() ){
            return 1;
        }    
        if( arr[i] != -1 ){
            return 1;
        }
        
        string p;
        for( int j = i ; j < A.length() ; ++j ){
            p += A[j];
            if( s.count(p) && isPossible(A , j+1 , s ) ){
                return 1;
            }
        }
        
        return arr[i] = 0;
        
    }
    
    int wordBreak(string A, vector<string> &B) {
        
        unordered_set<string> allWords;
        
        memset(arr, -1 , sizeof(arr));
        
        for( int i = 0 ; i < B.size() ; ++i ){
            allWords.insert(B[i]);        
        }
        
        return isPossible( A , 0 , allWords);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends