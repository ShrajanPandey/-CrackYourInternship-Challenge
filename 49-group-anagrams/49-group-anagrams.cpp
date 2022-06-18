class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        map<string,vector<string>> anagrams;
        
        for( int i = 0 ; i < str.size() ;++i ){
            string p = countSort(str[i]);
            anagrams[p].push_back(str[i]);
        }
        
        vector<vector<string>> ans;
        for( auto it = anagrams.begin() ; it != anagrams.end() ; ++it ){
            ans.push_back(it->second);
        }
        
        return ans;
        
    }
    
    string countSort(string &s){
        
        vector<int> count(26 , 0 );
        
        string res;
        for( int i = 0 ; i < s.length() ; ++i ){
            count[s[i]-'a']++;
        }
        
        for( int i = 0 ; i < 26 ; ++i ){
            if( count[i] ){
                string x(count[i], i + 'a');
                res += x;
            }
        }
        
        return res;
        
    }
    
};