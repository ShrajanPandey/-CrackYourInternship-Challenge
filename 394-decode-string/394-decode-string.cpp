class Solution {
public:
    map<int,int> m;
        
    string decode( string &s , int si , int ei ){
        if( s.length() == 0 ){
            return "";
        }
        
        string ans;
        int pre = 0;
        for( int i = si ;  i <= ei ; ++i ){
            if( s[i] >= '0' && s[i] <= '9' ){
                pre = pre*10 + (s[i]-'0');
            }
            else if( s[i] == '[' ){
                string n = decode(s , i+1 , m[i] );
                while( pre-- ){
                    ans += n;
                }
                i = m[i];
                pre = 0;
            }
            else if( s[i] == ']' ){
                continue;
            }   
            else{
                ans += s[i];
            }
        }
        
        return ans;
    }
    
    string decodeString(string s) {

        stack<int> openBracket;

        for( int i = 0 ; i < s.length() ; ++i ){
            if( s[i] == '[' ){
                openBracket.push(i);
            }    
            else if( s[i] == ']' ){
                int si = openBracket.top();
                openBracket.pop();
                m[si] = i;
            }
        }
        
        return decode(s, 0 , s.length()-1);
        
    }
};