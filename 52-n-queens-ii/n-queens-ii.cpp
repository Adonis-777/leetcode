class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n){

        // horizontal
        for(int i = 0; i < n; i++){
            if(board[row][i] == 'Q') return false;
        }

        //vertical
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q') return false;
        }

        //top left
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // top right
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){

        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int i = 0; i < n; i++){

            if(isSafe(board, row, i, n)){
                board[row][i] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans.size();
        
    }
};