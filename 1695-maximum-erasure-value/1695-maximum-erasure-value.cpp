class Solution {
public:
    //used prefix sum for storng all the sum before any calculations 
    //used unordered map to store last occurance index of an element
    //whenever any elements repeats itself just calculate the sum and update the index of that element 
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int i = 0 , j = 0;
        int ans = 0 , sum = 0;
        set<int> s;
        
        while( i < nums.size() && j < nums.size() ){
            
            if( s.count(nums[j]) == 0 ){
                sum += nums[j];
                ans = max( ans , sum);
                s.insert(nums[j]);
                ++j;
            }
            else{
                sum -= nums[i];
                s.erase(nums[i]);
                ++i;
            }
            
        }  
        
        return ans;
        
        
//         int s = 0;
//         unordered_map<int,int> m;
//         int ansS = 0;
        
//         vector<int> p;
//         for( int i = 0 ; i < nums.size() ;++i ){
//             s += nums[i];
//             p.push_back(s);
//         }
        
//         s = 0;
//         for( int i = 0 ; i < nums.size() ; ++i ){
            
//             if( m.count(nums[i]) && m[nums[i]] >= s ){
                
//                 ansS = max( ansS , p[i-1]-p[s] + nums[s]);
//                 s = max(s , m[nums[i]]+1);
        
//             }
            
//             m[nums[i]] = i;
            
//         }

//         ansS = max( ansS , p[nums.size()-1] - p[s] + nums[s] );
        
//         return ansS;
        
    }
};