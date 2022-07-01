class Solution {
public:
    bool static cmp( vector<int> &a , vector<int> &b){
        
        return  a[1] > b[1];
        
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int ans = 0;
        int curSize = 0;
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        
        for( int i = 0 ; i < boxTypes.size() && curSize < truckSize ; ++i ){
            
            int noOfBoxes = min(boxTypes[i][0],truckSize-curSize);
            curSize += noOfBoxes;
            ans += noOfBoxes*boxTypes[i][1];
            
        }
        
        return ans;
        
    }
};