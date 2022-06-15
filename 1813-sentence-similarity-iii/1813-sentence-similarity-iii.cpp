class Solution {
public:
    void wordFill( string &a , vector<string> &b ){
        
        string o;
        int n = a.length();
        
        for( int i = 0 ; i < n ;++i ){
            if( a[i] == ' ' ){
                b.push_back(o);
                o = "";
                continue;
            }
            o += a[i];
            if( i == n-1 ){
                b.push_back(o);
            }
        }
           
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        int n = sentence1.length() , m = sentence2.length();
        vector<string> a , b;
        
        wordFill(sentence1 , a );
        wordFill(sentence2 , b );
        
        int equalWords = 0;
        int i = 0 , j = 0;
        
        while( i < a.size() && j < b.size() ){
            if( a[i] != b[j] ){
                break;
            }
            ++i;
            ++j;
            ++equalWords;
        }
        
        int x = a.size()-1 , y = b.size()-1;
        
        while( x >= i && y >= j ){
            if( a[x] != b[y] ){
                break;
            }
            --x;
            --y;
            ++equalWords;
        }
        
        if( equalWords == a.size() || equalWords == b.size() ){
            return true;
        }
        
        return false;
        
    }
};