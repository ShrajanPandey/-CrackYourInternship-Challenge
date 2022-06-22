// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void generateAll(string &s , vector<string> &ans , string cur , vector<int> &used ,set<string> &st){
	        
	        bool allUsed = 1;
	       
	        for( int i = 0 ; i < s.length() ; ++i ){
	            if( used[i] == 0 ){
	                used[i] = 1;
	                generateAll(s , ans , cur + s[i] , used, st);
	                used[i] = 0;
	                allUsed = 0;
	            }
	        }
	        
	        if( allUsed ){
	            if( st.count(cur) == 0 ){
                    st.insert(cur);
	               ans.push_back(cur);
	            }
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    
		   vector<int> used(S.length(),0);
		   vector<string> ans;
		   set<string> st;
		   generateAll(S, ans , "", used,st);
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