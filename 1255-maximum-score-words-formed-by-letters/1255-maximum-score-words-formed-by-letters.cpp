class Solution {
public:
    int maxScore( vector<string> &words ,vector<int> &count , vector<int> &score , int si){
        
        int maxAns = 0;
        
        for( int i = si ; i < words.size() ; ++i ){
            
            bool isValid = 1;
            int res = 0;
            for( int j = 0 ; j < words[i].length() ; ++j ){
                count[words[i][j]-'a']--;
                if( count[words[i][j]-'a'] < 0 ){
                    isValid = 0;
                }
                res += score[words[i][j]-'a'];
            }
            
            if( isValid ){
                maxAns = max( maxAns, res + maxScore(words , count , score , i+1 ));
            }
            
            for( int j = 0 ; j < words[i].length() ; ++j ){
                count[words[i][j]-'a']++;
            }
            
        }
        
        return maxAns;

        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> count(26,0);
        for( int i = 0 ; i < letters.size() ; ++i ){
            count[letters[i]-'a']++;
        }
        
        return maxScore( words , count , score , 0 );
        
    }
};