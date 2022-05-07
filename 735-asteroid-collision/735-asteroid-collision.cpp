class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int> ans;
        vector<int> s;
        int n = ast.size();
        
        for( int i = 0 ; i < n ; ++i ){
            if( ast[i] > 0 ){
                s.push_back(ast[i]);
            }
            else{
                int cur = ast[i];
                while( s.size() != 0&& s.back() > 0 && cur < 0 ){
                    int a = s.back();
                    s.pop_back();
                    if( abs(cur) == a ){
                        cur = 0;
                    }
                    else if( abs(cur) < a ){
                        cur = 0;
                        s.push_back(a);
                    }
                }
                if( cur < 0 ){
                    s.push_back(cur);
                }
            }
        }
        
        
        return s;
        
    }
};