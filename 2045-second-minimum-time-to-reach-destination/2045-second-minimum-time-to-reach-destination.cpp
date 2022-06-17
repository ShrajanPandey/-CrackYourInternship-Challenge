class Solution {
public:
    int totalTime( int len , int change , int time ){
        
        int t = 0;
        int l = 0;
        while( l < len ){
                
            int a = t/change;
            if( a & 1 ){
                t += change - t%change;
            }
            t += time;
            ++l;
            
        }
        
        return t;
        
    }
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        unordered_map<int,vector<int>> graph;
        for( int i = 0 ; i < edges.size() ; ++i ){
            graph[edges[i][0]-1].push_back(edges[i][1]-1);
            graph[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        
        
        //bfs path from target to 1 calculating length of path 
        vector<int> d(n , 1e9);
        queue<int> pend;
        
        pend.push(n-1);
        d[n-1] = 0;
        
        while( pend.empty() == 0 ){
            
            int cur = pend.front();
            pend.pop();
            
            auto x = graph[cur];
            for( auto ver : x ){
                
                if( d[ver] == 1e9 ){
                    d[ver] = d[cur] + 1;
                    pend.push(ver);
                }
                
            }
            
        }
        
        int len = d[0]+2;
        pend.push(0);
        
        while( pend.empty() == 0 ){
            
            int cur = pend.front();
            pend.pop();
            
            bool complete = 0;
            
            for( auto ver : graph[cur] ){
                if( d[ver] == d[cur] ){//this means we found a path with length len + 1 
                    complete = 1;
                    len--;
                    break;
                }
                else if( d[ver] == d[cur] - 1 ){
                    pend.push(ver);
                }
            }
            
            if( complete ){
                break;
            }
            
        }

        return totalTime(len , change , time );
        
    }
};