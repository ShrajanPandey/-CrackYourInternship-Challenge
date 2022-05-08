class Solution {
public: 
    string decode( string &s , int &i ){
       
        int n = 0;
        string ans;
        while( i < s.length() ){
            
            if( isdigit(s[i]) ){
                n = n*10 + (s[i]-'0');
                ++i;
            }
            else if( s[i] == '[' ){
                    
                i++;
                string smallAns = decode(s , i);
                while( n-- ){
                    ans += smallAns;
                }
                n = 0;
                
            }
            else if( s[i] == ']' ){
                ++i;
                return ans;
            }
            else{
                ans += s[i];
                ++i;
            }
            
        }
        
        return ans;
        
    }
    
    string decodeString(string s) {
        
        int i = 0;
        return decode(s,i);
        
    }
};