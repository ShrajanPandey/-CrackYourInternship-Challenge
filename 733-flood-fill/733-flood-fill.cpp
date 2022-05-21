class Solution {
public:
    int n , m;
    
    void dfs( vector<vector<int>> &img ,int sr , int sc , int newColor , int col){
        
        if( sr >= n || sc >= m || sr < 0 || sc < 0 ){
            return;
        }
        
        if( img[sr][sc] != col ){
            return;
        }
        
        img[sr][sc] = newColor;
        
        dfs(img , sr+1 , sc , newColor , col);
        dfs(img , sr-1 , sc , newColor , col);
        dfs(img, sr , sc+1 , newColor , col);
        dfs(img, sr , sc-1 , newColor , col);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if( newColor == image[sr][sc] ){
            return image;
        }      
        
        n = image.size(), m = image[0].size();
        dfs(image , sr , sc , newColor , image[sr][sc]);
        
        return image;
        
    }
};