class Solution {
public:
    string normal( string s ){
        
        unordered_map<char,char> m;
        char curChar = 'a';
        
        for( int i = 0 ; i < s.length() ; ++i ){
            if( m.count(s[i]) ){
                s[i] = m[s[i]];
            }    
            else{
                m[s[i]] = curChar;
                s[i] = curChar;
                ++curChar;
            }
        }
        
        return s;
        
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        pattern = normal(pattern);
        
        for( int i = 0 ; i < words.size() ; ++i ){
            
            if( normal(words[i]) == pattern ){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
        
    }
};