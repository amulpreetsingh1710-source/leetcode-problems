class Solution {
public:

    void helper(int r, int c, vector<vector<char>> &grid){

        grid[r][c] = '0';

        if( c+1 < grid[0].size() && grid[r][c+1] == '1'){
            helper(r, c+1, grid);
        }
        if( c-1 >= 0 && grid[r][c-1] == '1'){
            helper(r, c-1, grid);
        }
        if( r+1 < grid.size() && grid[r+1][c] == '1'){
            helper(r+1, c, grid);
        }
        if( r-1 >= 0 && grid[r-1][c] == '1'){
            helper(r-1, c, grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols,false));

        int numOfIsl = 0;
        for(int i = 0; i< rows; i++){

            for(int j = 0; j< cols; j++){

                if(grid[i][j] == '1'){
                    helper(i, j, grid);
                    numOfIsl++;
                }
            }
        }

        return numOfIsl;
    }
};