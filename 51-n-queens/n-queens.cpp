class Solution {
public:

    bool isSafe(vector<string>& board,int row,int col,int n){
        //horizontal
        for(int j = 0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        //vertical
        for(int i = 0; i< n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //left upper diagonal
        for(int i = row,j = col; i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //right upper diagonal
        for(int i = row,j = col; i>=0 && j < n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string>& board,int row,int n,vector<vector<string>>& ans){
        
        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int col =0; col<n; col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][col] = '.';
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};