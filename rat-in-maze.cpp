#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Backtracking helper function to find all paths
void findPaths(vector<vector<int>>& maze, int r, int c, string currentPath, vector<string>& allPaths) {
    int n = maze.size();
    if(r < 0 || r >= n || c < 0 || c >= n || maze[r][c] == 0){
        return;
    }
    // Base Case: Destination reached
    if (r == n - 1 && c == n - 1) {
        allPaths.push_back(currentPath);
        return;
    }

    // Mark current cell as visited
    maze[r][c] = 0;

    // 1. Move Down
    findPaths(maze, r + 1, c, currentPath + 'D', allPaths);
    // 2. Move Left
    findPaths(maze, r, c - 1, currentPath + 'L', allPaths);
    // 3. Move Right
    findPaths(maze, r, c + 1, currentPath + 'R', allPaths);
    // 4. Move Up
    findPaths(maze, r - 1, c, currentPath + 'U', allPaths);
    
   

    // Unmark current cell (Backtracking)
    maze[r][c] = 1;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> allPaths;
    string currentPath = "";

    // Start only if the initial cell is open
    if (maze[0][0] == 1) {
        findPaths(maze, 0, 0, currentPath, allPaths);
    }

    // Print results
    if (allPaths.empty()) {
        cout << "No path found" << endl;
    }
    else {
        cout << "Possible Paths: " << endl;
        for (string path : allPaths) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
