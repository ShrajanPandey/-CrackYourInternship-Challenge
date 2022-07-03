class Solution {
public:
    void maxScore( vector<string> &words , map<char,int> &letters , vector<int> &score , int cur , int &ans , vector<int> &used ){
        
        ans = max( ans , cur);
        
        for( int i = 0 ; i < words.size() ; ++i ){
            
            if( used[i] == 0 ){
                used[i] = 1;
                
                bool no = 0;
                int curScore = 0;
                for( int j = 0 ; j < words[i].length() ; ++j ){
                    letters[words[i][j]]--;    
                    if( letters[words[i][j]] < 0 ){
                        no = 1;
                    }
                    curScore += score[words[i][j]-'a'];
                }
                
                if( no == 0 ){
                    // cout << words[i] << " " << curScore << endl;
                    maxScore(words , letters , score , curScore+cur , ans , used );
                    ans = max( ans , curScore);
                }

                for( int j = 0 ; j < words[i].length() ; ++j ){
                    letters[words[i][j]]++;
                }
                used[i] = 0;
            }
            
        }
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        map<char,int> freq;
        for( int i = 0 ; i < letters.size() ; ++i ){
            freq[letters[i]]++;
        }
        
        int ans = 0;
        vector<int> used(words.size()+1 , 0);
        maxScore( words , freq , score , 0 , ans , used);
        
        return ans;
        
    }
};