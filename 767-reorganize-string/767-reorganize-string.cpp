class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> count(26,0);
        
        int maxi = 0;
        int maxLet = 0;
        for( int i = 0 ; i < s.length() ; ++i ){
            count[s[i]-'a']++;
            maxi = max( maxi , count[s[i]-'a']);
            if(maxi == count[s[i]-'a']){
                maxLet = s[i]-'a';
            }
        }
        
        if( 2*maxi-1 > s.length() ){
            return "";
        }
        
        vector<char> ans(s.length());
        int idx = 0;
        while( count[maxLet] ){
            ans[idx] = (maxLet + 'a');
            idx += 2;
           count[maxLet]--;
        }
        
        for( int i = 0 ; i < 26 ; ++i ){
            
            while( count[i] ){
                
                if( idx >= s.length() ){
                    idx = 1;
                }
                ans[idx] = (i+'a');
                count[i]--;
                idx += 2;
                
            }
        }
        
        string p;
        for( int i = 0 ; i < ans.size() ; ++i ){
            p += ans[i];
        }
        
        return p;
        
    }
};