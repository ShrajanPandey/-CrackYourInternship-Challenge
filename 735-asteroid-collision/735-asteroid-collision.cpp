class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int> ans;
        stack<int> s;
        int n = ast.size();
        
        for( int i = 0 ; i < n ; ++i ){
            if( ast[i] > 0 ){
                s.push(ast[i]);
            }
            else{
                int cur = ast[i];
                while( s.size() != 0 && cur < 0 ){
                    int a = s.top();
                    s.pop();
                    if( abs(cur) == a ){
                        cur = 0;
                    }
                    else if( abs(cur) < a ){
                        cur = 0;
                        s.push(a);
                    }
                }
                if( cur < 0 ){
                    ans.push_back(cur);
                }
            }
        }
        
        vector<int> c;
        while( s.size() != 0 ){
            c.push_back(s.top());
            s.pop();
        }
        
        reverse(c.begin(),c.end());
        for( int i = 0; i < c.size() ; ++i ){
            ans.push_back(c[i]);
        }
        
        return ans;
        
    }
};