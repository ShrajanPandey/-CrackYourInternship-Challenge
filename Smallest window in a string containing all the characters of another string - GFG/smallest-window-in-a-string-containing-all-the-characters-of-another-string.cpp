// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        
        vector<int> all(26,0),cur(26,0);
        
        for( int i = 0 ; i < p.length() ; ++i ){
            all[p[i]-'a']++;
        }

        int len = INT_MAX;
        int si = -1 , ei = -1;
        int i = 0 , j = 0;
        int c = 0;
        
        while( i < s.length() && j < s.length() ){
            
            if( all[s[i]-'a'] ){
                
                cur[s[i]-'a']++;
                
                if( cur[s[i]-'a'] > all[s[i]-'a'] ){
                    
                    while( j < i ){
                        
                        if( all[s[j]-'a'] ){
                            if( cur[s[j]-'a'] > all[s[j]-'a'] ){
                                --cur[s[j]-'a'];
                            } 
                            else{
                                break;
                            }
                        }
                        
                        ++j;
                        
                    }

                } 
                else{
                    ++c;
                }
                
            }
            
            while( j < i && all[s[j]-'a'] == 0 ){
                ++j;
            }
            
            if( p.length() == c ){
        
                // cout << i-j+1 << " M " << endl;
                if( i-j+1 < len ){
                    si = j;
                    ei = i;
                    len = i-j+1;
                }
            }
            ++i;
            
        }
        
        if( si == -1 ){
            return "-1";
        }

        return s.substr(si,len);
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends