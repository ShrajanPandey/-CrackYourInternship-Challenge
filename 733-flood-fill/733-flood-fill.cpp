class Solution {
public:
    void dfs( vector<vector<int>> &image , int sr , int sc , int color , int newColor ){
        
        if( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != newColor ){
            return;
        }
        
        image[sr][sc] = color;
        
        dfs(image , sr+1 , sc , color, newColor);
        dfs(image , sr , sc+1 , color, newColor);
        dfs(image , sr , sc-1 , color, newColor);
        dfs(image , sr-1 , sc , color, newColor);

        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if( image[sr][sc] == color ){
            return image;
        }
        
        dfs(image , sr , sc , color,image[sr][sc]);
        return image;
        
    }
};