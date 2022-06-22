class Solution {
public:
    void generateAll( int n , int k , string curNo , vector<int> &ans ){
        
        if( n == 0 ){
            ans.push_back(stoll(curNo));
            return;
        }
        
        int lastDigit = curNo[curNo.length()-1]-'0';
        if( lastDigit + k <= 9 ){
            generateAll(n-1 , k , curNo + (char)(lastDigit+k+'0'), ans);
        }
        if( k != 0 && lastDigit-k >= 0 ){
            generateAll(n-1 , k , curNo + (char)(lastDigit-k+'0'), ans);
        }
     
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        queue<int> numbers;
        for( int i = 1 ; i <= 9 ; ++i ){
            numbers.push(i);
        }
        
        --n;
        while( n-- ){
            
            int size = numbers.size();
        
            for( int i = 0 ; i < size ; ++i ){
                
                int curNum = numbers.front();
                int lastDigit = curNum%10;
                
                numbers.pop();
                
                if(lastDigit + k <= 9 ){
                    numbers.push(curNum*10 + lastDigit+k);
                }
                if( k != 0 && lastDigit-k >= 0 ){
                    numbers.push(curNum*10 + lastDigit-k);
                }
                
            }
            
            if( n == 0 ){
                break;
            }
            
        }
        
        vector<int> ans;
        
        while( numbers.empty() != 1 ){
            ans.push_back(numbers.front());
            numbers.pop();
        }
        
        return ans;
        
    }
};