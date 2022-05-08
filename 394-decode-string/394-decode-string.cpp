class Solution {
public: 
    string decode( string &s , int &i ){
       
        string ans;
        while( i < s.length() && s[i] != ']' ){
            
            if( isdigit(s[i]) == 0 ){
                ans += s[i++];
            }
            else{
                int n = 0;
                while( isdigit(s[i]) && i < s.length() ){
                    n = n*10 + (s[i]-'0');
                    ++i;
                }
                
                ++i;//[
                string smallAns = decode(s , i);
                ++i;//]
                
                while( n-- ){
                    ans += smallAns;
                }
            }
            
        }
        
        return ans;
        
    }
    
    string decodeString(string s) {
        
        int i = 0;
        return decode(s,i);
        
    }
};