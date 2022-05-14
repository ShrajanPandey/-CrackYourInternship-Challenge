class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int l) {
        
        if( l == 1 ){
            return 1;
        }
        
        sort(t.begin(),t.end());
        long long ans = 0, ll = t[t.size()-1][1];
        
        map<int,int> m,p;
        int tt = 0;
        for( int i = 0 ; i < t.size() ; ++i ){
            
            tt += t[i][1] - t[i][0] + 1;
            m[t[i][0]] = tt;
            p[t[i][0]] = t[i][1];
            // cout << tt << endl;
        }
        
        for( int i = 0; i < t.size() ; ++i ){
            
            if( tt - m[t[i][0]] + t[i][1] - t[i][1] + 1 < ans ){
                break;
            }
            
            long long len = 0, s = t[i][0], e = s + l - 1;
            auto x = m.lower_bound(e);
            if( x != m.end() && x->first == e ){
                // cout << "OP" << x->second << endl;
                len = x->second - (p[x->first]-x->first);
            }
            else{
                --x;
                len = x->second;
                if( p[x->first] > e ){
                    len -= (p[x->first]-x->first);
                    len += e - x->first;
                }
            }
            len -= (m[t[i][0]] - (t[i][1] - t[i][0] + 1));
            // cout << len << " " << endl;
            // cout << len << " " << t[i][0] << " " << e << endl;
            ans = max(ans,len);
            
        }
        
        return ans;
        
    }
};