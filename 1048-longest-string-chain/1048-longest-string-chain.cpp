class Solution {
public:
    static bool cmp(string a , string b ){
        return a.length() < b.length();
    }
    
    int memo[1001][1001];
    int maxChainLen(vector<string> &words , int i , int pre ){
        
        if( i == words.size() ){
            return 0;
        }
        
        if( pre != -1 && memo[i][pre] != -1 ){
            return memo[i][pre];
        }
        
        int ans = 0;
        for( int j = i ; j < words.size() ; ++j ){
            
            if( pre != -1 ){
                if( words[j].length() > words[pre].length()+1 ){
                    break;
                }
                else if( words[j].length() != words[pre].length()+1 ){
                    continue;
                }
                
                int k = 0 , l = 0;
                while( k < words[j].length() && l < words[pre].length() ){
                    if( words[j][k] == words[pre][l] ){
                        ++k;
                        ++l;
                    }
                    else{
                        ++k;
                    }
                }
                
                int a = abs((int)words[j].length() - k);
                if( l == words[pre].length() && ( a == 0 || a == 1 ) ){
                    ans = max( ans , 1 + maxChainLen(words, j+1 , j) );
                }
        
            }   
            else{
                ans = max( ans , 1+maxChainLen(words, j+1 , j ) );
            }
        }
        
        if( pre == -1 ){
            return ans;
        }
        
        return memo[i][pre] = ans;
        
    }
            
    int longestStrChain(vector<string>& words , int i = 0) {
        
        memset( memo , -1 , sizeof(memo));
        sort(words.begin(),words.end(),cmp);
        return maxChainLen(words , 0 , -1);
        
    }

};