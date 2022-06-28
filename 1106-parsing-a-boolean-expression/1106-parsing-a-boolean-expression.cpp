class Solution {
public:
    bool parseBoolExpr(string expression) {
        
        stack<char> toEval;

        for( int i = 0 ; i < expression.length() ; ++i ){
            
            if( expression[i] == ')' ){
                
                vector<char> smallExpressions;
                
                while( toEval.empty() != 1 ){
                    
                    char c = toEval.top();
                    toEval.pop();
                    
                    if( c == '(' ){
                        break;
                    }
                    else if( c == ',' ){
                        continue;
                    } 
                    else{
                        smallExpressions.push_back(c);
                    }
                    
                }
    
                bool ans = smallExpressions[0] == 't';
                if( toEval.empty() ){
                    toEval.push(( ans == 1 ? 't' : 'f'));
                    break;
                }
                
                char operation = toEval.top();
                toEval.pop();
                
                if( operation == '&' ){
                    for( int i = 0 ; i < smallExpressions.size() ; ++i ){
                        ans &= ( smallExpressions[i] == 't' );
                    }
                }
                else if( operation == '|' ){
                    for( int i = 0 ; i < smallExpressions.size() ; ++i ){
                        ans |= ( smallExpressions[i] == 't' );
                    }
                }
                else if( operation == '!' ){
                    ans ^= 1;
                }
                
                toEval.push(( ans == 1 ? 't' : 'f') );

            }
            else{
                toEval.push(expression[i]);
            }
            
        }
        
        return toEval.top() == 't';
        
    }
};