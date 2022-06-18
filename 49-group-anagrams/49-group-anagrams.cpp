class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        
        map<string,vector<string>> anagrams;
        
        for( int i = 0 ; i < str.size() ;++i ){
            string p = str[i];
            sort(p.begin(),p.end());
            anagrams[p].push_back(str[i]);
        }
        
        vector<vector<string>> ans;
        for( auto it = anagrams.begin() ; it != anagrams.end() ; ++it ){
            ans.push_back(it->second);
        }
        
        return ans;
        
    }
};