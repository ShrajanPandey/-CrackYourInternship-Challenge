// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    map<string,int> arr;
        
    int minLength( string &start , string &target , vector<string> &list , vector<int> &used){
        
        if( start == target ){
            return 1;
        }
        
        if( arr.count(start) ){
            return arr[start];
        }
        
        int minMoves = INT_MAX;
        
        for( int i = 0 ; i < list.size() ; ++i ){
            
            if( used[i] == 0 && start != list[i] ){
                
                int count = 0;

                for( int k = 0 ; k < start.length() ; ++k ){
                    
                    if( start[k] != list[i][k] ){
                        ++count;
                    }
                    
                }
                
                if( count == 1 ){
                    
                    used[i] = 1;
                    int moves = minLength( list[i] , target , list , used);
                     used[i] = 0;
                    if( moves == INT_MAX ){
                        continue;
                    }

                    minMoves = min( minMoves , 1 + moves );
                }
                
            }
           
        }
        
        return arr[start] = minMoves;
        
    }
    
    int wordLadderLength(string start, string target, vector<string>& list) {
        
        // vector<int> used(wordList.size(),0);
        // // sort(wordList.begin(),wordList.end());
        // arr.clear();
        // int ans =  minLength(startWord , targetWord , wordList , used);
        // return ( ans == INT_MAX ? 0 : ans );
        
        unordered_set<string> dic(list.begin(),list.end());
        queue<string> todo;
        todo.push(start);
        
        int ladder = 1;
        
        while( todo.empty() != 1 ){
            
            int size = todo.size();
            
            for( int i = 0 ; i < size ; ++i ){
                
                string curWord = todo.front();
                todo.pop();
                
                if( curWord == target ){
                    return ladder;
                }
                
                dic.erase(curWord);
                
                for( int j = 0 ; j < curWord.length() ; ++j ){
                    
                    int c = curWord[j];
                    
                    for(int p = 0 ; p < 26 ; ++p ){
                        curWord[j] = 'a'+p;
                        if( dic.count(curWord) ){
                            dic.erase(curWord);
                            todo.push(curWord);
                        }
                    }
                    
                    curWord[j] = c;
                    
                }
            }
            
            ++ladder;
            
        }
        
        return 0;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends