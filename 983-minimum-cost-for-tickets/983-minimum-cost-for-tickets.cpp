class Solution {
public:
    int arr[1000];
    int minCost( vector<int> &days , vector<int> &costs , int si ){
        
        if( si >= days.size() ){
            return 0;
        }
        
        if( arr[si] != -1 ){
            return arr[si];
        }
        int a = INT_MAX , c = INT_MAX ,b = INT_MAX;
        
        b = minCost( days , costs , si+1) + costs[0];
        
        int i = 0;
        for( i = si ; i < days.size() && days[i] < days[si]+7 ; ++i );
        a = minCost(days , costs , i) + costs[1];
        
        for( i = si ; i < days.size() && days[i] < days[si]+30 ; ++i );
        c = minCost( days , costs , i) + costs[2];
        
        return arr[si] = min(min(b , c) ,a);
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(arr , -1 , sizeof(arr));
        return minCost( days , costs , 0  );
                   
    }
};