class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 'O' || vis[row][col])
            return;

        vis[row][col] = 1;
        dfs(vis, grid, row + 1, col, n, m);
        dfs(vis, grid, row - 1, col, n, m);
        dfs(vis, grid, row, col + 1, n, m);
        dfs(vis, grid, row, col - 1, n, m);
    }

    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Check for borders
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 'O' && !vis[i][j]) {
                    dfs(vis, grid, i, j, n, m);
                }
            }
        }

        // Mark remaining 'O's as 'X' and reset visited flag
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !vis[i][j]) {
                    grid[i][j] = 'X';
                }
                // vis[i][j] = 0; // Reset visited flag for future use
            }
        }
    }
};
