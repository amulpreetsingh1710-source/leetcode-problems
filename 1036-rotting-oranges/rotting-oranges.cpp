class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Collect all starting rotten oranges and count fresh ones
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // Step 2: Run multi-source BFS level by level
        while(q.size() != 0){
            int levelSize = q.size();
            bool flag = false;

            for(int i = 0; i < levelSize; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(c + 1 < cols && grid[r][c + 1] == 1){
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                    fresh--;
                    flag = true;
                }
                if(c - 1 >= 0 && grid[r][c - 1] == 1){
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                    fresh--;
                    flag = true;
                }
                if(r + 1 < rows && grid[r + 1][c] == 1){
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                    fresh--;
                    flag = true;
                }
                if(r - 1 >= 0 && grid[r - 1][c] == 1){
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                    fresh--;
                    flag = true;
                }
            }

            if(flag == true){
                minutes++;
            }
        }

        // Step 3: Verify no fresh oranges were walled off
        if(fresh > 0) return -1;
        return minutes;
    }
};
