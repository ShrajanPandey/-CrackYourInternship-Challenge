// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       
        int size1 = s1.length() , size2 = s2.length();
        string ans;
        
        int neg = 0;
        if( s1[0] == '-' ){
            ++neg;
            s1 = s1.substr(1);
            --size1;
        }
        if( s2[0] == '-' ){
            ++neg;
            s2 = s2.substr(1);
            --size2;
        } 
        

        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        if( (size1 == 1 && s1 == "0") || (size2 == 1 && s2 == "0") ){
            return "0";
        }
        
        for( int i = 0 ; i < size1 ; ++i ){
            
            string curPro;
            int carry = 0;
            for( int j = 0 ; j < size2 ; ++j ){
                
                int pro = (s1[i]-'0')*(s2[j]-'0') + carry;
                carry = pro/10;
                curPro += (pro%10 + '0');
                
            }
        
            if( carry ){
                curPro += (carry + '0');
            }
            
            if( i == 0 ){
                ans = curPro;
            }
            else{
                
                carry = 0;
                int l = i , k = 0;
                while( l < ans.length() && k < curPro.length() ){
                    
                    int sum = (ans[l]-'0') + (curPro[k]-'0') + carry;
                    carry = sum/10;
                    ans[l] = sum%10 + '0';
                    ++l;
                    ++k;
                    
                }
                
                while( l < ans.length() && carry != 0 ){
                    
                    int sum = (ans[l] - '0') + carry;
                    ans[l] = sum%10 + '0';
                    carry = sum/10;
                    ++l;
                    
                }
                
                while( k < curPro.length() ){
                    
                    int sum = (curPro[k] - '0') + carry;
                    carry = sum/10;
                    ans += sum%10 + '0';
                    ++k;
                    
                }
                
                if( carry ){
                    ans += (carry + '0');
                }
                
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        
        for( int i = 0 ; i < ans.length() ; ++i ){
            if( ans[i] != '0' ){
                ans = ans.substr(i);
                break;
            }
        }
        
        if( neg == 1 ){
            ans = '-' + ans;
        }
        
        return ans;
        
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends