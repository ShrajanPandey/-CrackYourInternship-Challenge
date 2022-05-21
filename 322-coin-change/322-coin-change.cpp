class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if( amount == 0 ){
            return 0;
        }
        
        queue<int> que;
        que.push(amount);
        vector<bool> visited( amount , 0);
        int curLevel = 1;
        
        while( que.size() != 0 ){
            
            int size = que.size();
            for( int i = 0 ; i < size ; ++i ){
                
                int cur = que.front();
                que.pop();
                
                for( auto r : coins ){
                    int curval = cur - r;
                    if( curval == 0 ){
                        return curLevel;
                    }
                    else if( curval > 0 && visited[curval] == 0 ) {
                        visited[curval] = 1;
                        que.push(curval);
                    }
                }
                
            }
            
            ++curLevel;
            
        }
        
        return -1;
        
    }
};