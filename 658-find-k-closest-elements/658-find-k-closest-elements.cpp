class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        priority_queue <int> pq;
        
        for( int i = 0 ; i < arr.size() ; ++i ){
            pq.push(abs(arr[i]-x));
            if( pq.size() > k ){
                pq.pop();
            }
        }
        
        map<int,int> m;
        while( pq.empty() != 1 ){
            m[pq.top()]++;
            pq.pop();
        }
        
        for( int i = 0 ; i < arr.size() ; ++i ){
            if( m.count(abs(arr[i]-x)) && m[abs(arr[i]-x)] > 0 ){
                ans.push_back(arr[i]);
                m[abs(arr[i]-x)]--;
                if( ans.size() == k ){
                    return ans;
                }
            }
        }
        
        return ans;
        
    }
};