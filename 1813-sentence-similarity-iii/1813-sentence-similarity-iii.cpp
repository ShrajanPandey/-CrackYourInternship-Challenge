class Solution {
public:
    void wordFill( string &a , deque<string> &b ){
        
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
        deque<string> a , b;
        
        wordFill(sentence1 , a );
        wordFill(sentence2 , b );
        
        while( a.empty() == 0 && b.empty() == 0 ){
            
            if( a.front() == b.front() ){
                a.pop_front();
                b.pop_front();
            }
            else if( a.back() == b.back() ){
                a.pop_back();
                b.pop_back();
            }
            else{
                break;  
            }
            
        }
        
        return ( a.empty() || b.empty() );
        
    }
};