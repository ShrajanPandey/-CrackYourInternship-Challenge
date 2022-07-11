class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> count , cur;
        
        for( int i = 0 ;i < t.length() ; ++i ){
            count[t[i]]++;
        }
        
        int start = 0 , end = 0;
        int ans = INT_MAX , equalChars = 0, fstart = -1;
        
        while( end < s.length() ){
            
            if( count.count(s[end]) ){
                cur[s[end]]++;
                if( cur[s[end]] <= count[s[end]] ){
                    ++equalChars;
                }
            }
            
            if( equalChars == t.length() ){
                
                while( start < end ){
                    
                    if( count.count(s[start]) ){
                        if( cur[s[start]] == count[s[start]] ){
                            break;
                        }
                        --cur[s[start]];
                    }
                    ++start;
                    
                }
                
                if( ans > end-start+1 ){
                    fstart = start;
                }
                ans = min( ans , end - start + 1 );
                
                while( start < end && equalChars == t.length() ){
                    if( count.count(s[start]) ){
                        if( cur[s[start]] == count[s[start]] ){
                            --cur[s[start]];
                            --equalChars;
                        }
                    }
                    ++start;
                }
                
            }
            
            ++end;
        }
        
        return (fstart == -1 ? "" : s.substr(fstart,ans));
        
    }
};