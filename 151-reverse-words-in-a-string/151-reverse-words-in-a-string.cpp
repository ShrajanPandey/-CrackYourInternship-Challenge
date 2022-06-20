class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> words;
        string a;
        
        for( int i = 0 ; i < s.length() ; ++i ){
            if( s[i] == ' ' ){
                if( a.length() )
                    words.push(a);
                a = "";
                continue;
            }    
            
            a += s[i];
        }
        
        if( a.length() ){
            words.push(a);
        }
        
        string ans;
        while( words.empty() != 1 ){
            
            ans += words.top();
            words.pop();
            if( words.size() ){
                ans += ' ';
            }
            
        }
        
        return ans;

    }
};