class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int color){
        if(r >= image.size() || r < 0 || c< 0 || c >= image[0].size() || image[r][c] != oldColor){
            return;
        }
        image[r][c] = color;
        dfs(image, r,c+1,oldColor, color);
        dfs(image, r,c-1,oldColor, color);
        dfs(image, r+1,c,oldColor, color);
        dfs(image, r-1,c,oldColor, color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == color){
            return image;
        }
        else{
            int oldColor = image[sr][sc];
            dfs(image, sr, sc, oldColor, color);
        }

        return image;
    }
};