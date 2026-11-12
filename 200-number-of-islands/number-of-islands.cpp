class Solution {
public:

    void helper(int r, int c, vector<vector<bool>> &vis,vector<vector<char>> &grid){

        vis[r][c] = true;

        if( c+1 < grid[0].size() && grid[r][c+1] == '1' && vis[r][c+1] == false){
            helper(r, c+1, vis, grid);
        }
        if( c-1 >= 0 && grid[r][c-1] == '1' && vis[r][c-1] == false){
            helper(r, c-1, vis, grid);
        }
        if( r+1 < grid.size() && grid[r+1][c] == '1' && vis[r+1][c] == false){
            helper(r+1, c, vis, grid);
        }
        if( r-1 >= 0 && grid[r-1][c] == '1' && vis[r-1][c] == false){
            helper(r-1, c, vis, grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols,false));

        int numOfIsl = 0;
        for(int i = 0; i< rows; i++){

            for(int j = 0; j< cols; j++){

                if(grid[i][j] == '1' && vis[i][j] == false){
                    helper(i, j, vis, grid);
                    numOfIsl++;
                }
            }
        }

        return numOfIsl;
    }
};