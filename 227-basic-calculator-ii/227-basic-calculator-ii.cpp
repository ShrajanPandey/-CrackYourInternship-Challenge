class Solution {
public:
    int calculate(string s) {
        
        if( s.length() == 0 ){
            return 0;
        }
        
        deque<string> toEval;
        int i = 0;
        int n = s.length();
        int ans = 0;
        
        while( i < n ){
             
            string pre;
            if( toEval.size() ){
                pre = toEval.back();
            }
            
            while( i < n && s[i] == ' ' ){
                ++i;
            }
            
            string cur;
            while( i < n && (s[i] >= '0' && s[i] <= '9') ){
                cur += s[i];
                ++i;
            }
            
            if( pre == "*" || pre == "/" ){
                
                toEval.pop_back();
                string first = toEval.back();
                toEval.pop_back();
                
                int smallAns = 0;
                if( pre == "*" ){
                    smallAns = stoi(first)*stoi(cur);
                }
                if( pre == "/" ){
                    smallAns = stoi(first)/stoi(cur);
                }
                
                toEval.push_back(to_string(smallAns));
                
            }
            else if( cur.length() ){
                toEval.push_back(cur);
            }
            
            while( i < n && s[i] == ' ' ){
                ++i;
            }
            
            string operand = "";
            if( i < n && (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' ) ){
                operand += s[i];
                ++i;
            }
            
            if( operand.length() ){
                toEval.push_back(operand);
            }

        }
        
        // cout << toEval.size() << endl;
        
        while( toEval.size() > 1 ){
            
            string first = toEval.front();
            toEval.pop_front();
            string op = toEval.front();
            toEval.pop_front();
            string second = toEval.front();
            toEval.pop_front();
            
            // cout << first << " " << op << " " << second << endl;
            if( op == "+" ){
                toEval.push_front(to_string(stoi(second) + stoi(first)));
            }
            if( op == "-" ){
                toEval.push_front(to_string(stoi(first) - stoi(second)));
            }
            
        }
        
        return stoll(toEval.front());
        
    }
};