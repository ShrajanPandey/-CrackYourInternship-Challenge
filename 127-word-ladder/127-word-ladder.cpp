class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        
        int ladder = 1;
        
        while( todo.empty() != 1 ){
            
            int size = todo.size();
            
            for( int i = 0 ; i < size ; ++i ){
                
                string curWord = todo.front();
                todo.pop();
                
                if( curWord == endWord ){
                    return ladder;
                }
                
                dict.erase(curWord);
                
                for(int j = 0 ; j < curWord.length() ; ++j ){
                    int p = curWord[j];
                    for( int i = 0 ; i < 26 ; ++i ){
                        char c = 'a'+i;
                        curWord[j] = c;
                        if( dict.count(curWord) ){
                            todo.push(curWord);
                            dict.erase(curWord);
                        }
                    }
                    curWord[j] = p;
                }
                
            }
            
            ++ladder;
            
        }
        
        return 0;
        
    }
};