class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<pair<string,int>>> p(26);
        
        int ans = 0;
        
        for( int i = 0 ; i < words.size() ; ++i ){
            p[words[i][0]-'a'].push_back({words[i],0});    
        }
        
        for( int i = 0 ; i < s.length() ; ++i ){
            
            vector<pair<string,int>> cur = p[s[i]-'a'];
            p[s[i]-'a'].clear();
            
            for( int i = 0 ; i < cur.size() ; ++i ){
                
                cur[i].second++;
                if( cur[i].second == cur[i].first.length() ){
                    ++ans;
                }
                else{
                    p[cur[i].first[cur[i].second]-'a'].push_back(cur[i]);
                }
                
            }
            
        }
        
        return ans;
        
        
    }
};