class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long pre;
        
        set<long long> s;
        s.insert(1);
        
        while( n-- ){
            
            pre = pq.top();
            pq.pop();
            
            long long a = pre * 2;
            long long b = pre*3;
            long long c = pre * 5;
            
            if( !s.count(a) ){
                s.insert(a);
                pq.push(a);
            }
            if( !s.count(b) ){
                s.insert(b);
                pq.push(b);
            }
            if( !s.count(c) ){
                s.insert(c);
                pq.push(c);
            }
            
            
        }
        
        
        return pre;
        
    }
};