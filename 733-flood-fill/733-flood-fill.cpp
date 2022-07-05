class Solution {
public:
    void dfs( vector<vector<int>> &image , int sr , int sc , int color ){
        
        if( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ){
            return;
        }
        
        int curColor = image[sr][sc];
        image[sr][sc] = color;
        
        if( sr + 1 < image.size() && image[sr+1][sc] == curColor ){
            dfs(image, sr+1 , sc , color);
        }
        if( sc+1 < image[0].size() && image[sr][sc+1] == curColor ){
            dfs(image , sr , sc+1 , color);
        }
        if( sc-1 >= 0 && image[sr][sc-1] == curColor ){
            dfs(image , sr , sc-1 , color);
        }
        if( sr-1 >= 0 && image[sr-1][sc] == curColor ){
            dfs(image , sr-1 , sc , color);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if( image[sr][sc] == color ){
            return image;
        }
        
        dfs(image , sr , sc , color);
        return image;
        
    }
};