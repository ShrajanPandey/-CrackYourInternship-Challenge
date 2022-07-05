// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
       void Painter(vector<vector<int>> &image,int i,int j,int color,int row,int col,int validColor){
        
        // base case
        // checking if we are out of bound or image we are on is already visited or we stand on wrong pixel
        
        if(i < 0 or j < 0 or i >= row or j >= col or image[i][j] != validColor){
            return;
        }
        
        // if image is valid image , than paint it
        image[i][j] = color;
        
        // travel 
        Painter(image,i-1,j,color,row,col,validColor); // Up
        Painter(image,i+1,j,color,row,col,validColor); // down
        Painter(image,i,j-1,color,row,col,validColor); // left
        Painter(image,i,j+1,color,row,col,validColor); // right
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         // size of row and col
        int row = image.size();
        int col = image[0].size();
        
        // valid color which can be colored
        int validColor = image[sr][sc];
        
        // if source is already painted
        if(validColor == color){
            return image;
        } 
        
        // calling painter function for help
        Painter(image,sr,sc,color,row,col,validColor);
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends