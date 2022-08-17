class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ans;
        for( int i = 0 ; i < words.size() ; ++i ){
            string cur;
            for( int j = 0 ; j < words[i].length() ; ++j ){
                cur += v[words[i][j]-'a'];
            }
            ans.insert(cur);
        }
        
        return ans.size();
        
    }
};