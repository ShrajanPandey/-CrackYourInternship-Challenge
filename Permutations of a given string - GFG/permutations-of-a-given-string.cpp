// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void generateAll(string &s , vector<string> &ans , int cur , unordered_set<string> &u){
	        
	        if( cur >= s.length()-1 ){
	            if( u.count(s) == 0 ){
	                ans.push_back(s);
	                u.insert(s);
	            }
	            return;
	        }
	        
	        for( int i = cur ; i < s.length() ; ++i ){
	            swap(s[cur],s[i]);
	            generateAll(s , ans ,cur+1,u);
	            swap(s[cur],s[i]);
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    
		   unordered_set<string> u;
		   vector<string> ans;
		   generateAll(S , ans , 0,u);
		   sort(ans.begin(),ans.end());
		   return ans;
		   
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends