class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> count(26,0);
        
        int maxi = 0;
        for( int i = 0 ; i < s.length() ; ++i ){
            count[s[i]-'a']++;
            maxi = max( maxi , count[s[i]-'a']);
        }
        
        if( 2*maxi-1 > s.length() ){
            return "";
        }
        
        
        string ans;
        priority_queue<pair<int,char>> pq;
        
        for( int i = 0 ; i < 26 ; ++i ){
            if( count[i] ){
                pq.push({count[i],(char)(i+'a')});
            }
        }
        
        while( pq.empty() != 1 ){
            
            pair<int,char> a = pq.top();
            pq.pop();
            
            if( pq.empty() ){
                ans += a.second;
                break;
            }
            
            while( a.first && pq.empty() != 1 ){
                pair<int,int> b = pq.top();
                pq.pop();
                ans += a.second;
                ans += b.second;
                b.first--;
                a.first--;
                if( b.first ){
                    pq.push(b);
                }
            }
            
            if( pq.empty() && a.first ){
                ans += a.second;
            }
            
        }
       
        
        return ans;
        
    }
};