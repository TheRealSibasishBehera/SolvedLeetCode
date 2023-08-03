class Solution {
public:
    int dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] || grid[row][col] == 0)
            return 0;

        vis[row][col] = 1;
        int count = 1;
        count += dfs(vis, grid, row + 1, col, n, m);
        count += dfs(vis, grid, row - 1, col, n, m);
        count += dfs(vis, grid, row, col + 1, n, m);
        count += dfs(vis, grid, row, col - 1, n, m);
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    // cout<<"hello"<<endl;
                    if (grid[i][j] == 1 && vis[i][j] == 0) {
                        // cout<<"hello"<<endl;

                        dfs(vis, grid, i, j, n, m);
                    }
                }
            }
        }
        int count =0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j] ) {
                            // cout<<i<<" "<<j<<endl;

                    // count++;
                    count+=dfs(vis, grid, i, j, n, m);
                }
            }
        }

        return count;
    }
};