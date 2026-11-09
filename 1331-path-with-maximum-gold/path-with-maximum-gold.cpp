class Solution {
public:

    int ans = 0;
    bool isSafe(vector<vector<int>>& board, int row, int col, int m, int n, vector<vector<int>>& visited){
        if(row >= 0 && row < m && col >= 0 && col < n && board[row][col] != 0 && visited[row][col] == 0)
            return true;
        return false;
    }


    void solve(vector<vector<int>>& board, int row, int col, int m, int n, vector<vector<int>>& visited, int currSum){
        if(row == m || col == n){
            ans = max(ans, currSum);
            return;
        }

        if(board[row][col] == 0)
            return;
        visited[row][col] = 1;
        currSum += board[row][col];

        
        ans = max(ans, currSum);

        // going up
        if(isSafe(board, row - 1, col, m, n, visited)){
            solve(board, row - 1, col, m, n, visited, currSum);
        }

        // going down
        if(isSafe(board, row + 1, col, m, n, visited)){
            solve(board, row + 1, col, m, n, visited, currSum);
        }

        // going right
        if(isSafe(board, row, col + 1, m, n, visited)){
            solve(board, row, col + 1, m, n, visited, currSum);
        }

        // going left
        if(isSafe(board, row, col - 1, m, n, visited)){
            solve(board, row, col - 1, m, n, visited, currSum);
        }

        // backtrack
        visited[row][col] = 0;
        currSum -= board[row][col];
    }

    int getMaximumGold(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != 0){
                    solve(board, i, j, m, n, visited, 0);  
                }
            }
        }

        return ans;
        
    }
};