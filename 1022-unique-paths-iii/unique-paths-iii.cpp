class Solution {
public:

    int count = 0;

    bool isSafe(vector<vector<int>>& grid, int row, int col, int m, int n,
                vector<vector<int>>& visited) {

        if(row >= 0 && row < m && col >= 0 && col < n &&
           grid[row][col] != -1 && visited[row][col] == 0) {
            return true;
        }

        return false;
    }

    bool check(vector<vector<int>>& grid, vector<vector<int>>& visited) {

        int m = visited.size();
        int n = visited[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != -1 && visited[i][j] == 0)
                    return false;
            }
        }

        return true;
    }

    void solve(vector<vector<int>>& grid, int row, int col, int m, int n,
               vector<vector<int>>& visited) {

        visited[row][col] = 1;

        if(grid[row][col] == 2) {

            if(check(grid, visited))
                count++;

            visited[row][col] = 0;
            return;
        }

        // Going up
        if(isSafe(grid, row - 1, col, m, n, visited))
            solve(grid, row - 1, col, m, n, visited);

        // Going down
        if(isSafe(grid, row + 1, col, m, n, visited))
            solve(grid, row + 1, col, m, n, visited);

        // Going right
        if(isSafe(grid, row, col + 1, m, n, visited))
            solve(grid, row, col + 1, m, n, visited);

        // Going left
        if(isSafe(grid, row, col - 1, m, n, visited))
            solve(grid, row, col - 1, m, n, visited);

        // Backtracking
        visited[row][col] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        count = 0;

        int m = grid.size();
        int n = grid[0].size();

        // Identify starting coordinates
        int start_row, start_col;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    start_row = i;
                    start_col = j;
                    break;
                }
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));

        solve(grid, start_row, start_col, m, n, visited);

        return count;
    }
};