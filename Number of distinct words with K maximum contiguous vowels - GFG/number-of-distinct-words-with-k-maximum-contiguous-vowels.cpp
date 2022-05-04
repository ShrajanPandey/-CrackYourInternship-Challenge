// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    int mod = 1e9+7;
    
    long long noOfWords(int n , int k , int countVowels, vector<vector<int>> &m ){
        
        if( n == 0 ){
            return 1;
        }
        
        if( m[n][countVowels] != -1 ){
            return m[n][countVowels];
        }
        
        long long vowels = 0 , noVowels = 0;
        if( countVowels < k )
            vowels = (5*noOfWords( n-1 , k , countVowels+1, m )%mod)%mod;
        noVowels = (21*noOfWords(n-1 , k , 0 ,m)%mod)%mod;
        
        return m[n][countVowels] = ((long long)vowels + noVowels)%mod;
        
    }
    
    int kvowelwords(int N, int K) {
        
        vector<vector<int>> v(N+1);
        for( int i = 0 ; i <= N ; ++i ){
            v[i] = vector<int> (K+1,-1);
        }
        return noOfWords(N , K , 0, v);
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends