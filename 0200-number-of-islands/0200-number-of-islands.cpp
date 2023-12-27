#include <vector>

using namespace std;

class Solution {
public:
    int counte = 0;

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &clone, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || clone[i][j] == 1) {
            return;
        }

        // set the clone
        clone[i][j] = 1;

        // visit the possible 4 ways (up, down, left, right)
        dfs(grid, clone, i - 1, j); // up
        dfs(grid, clone, i + 1, j); // down
        dfs(grid, clone, i, j - 1); // left
        dfs(grid, clone, i, j + 1); // right
    }

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1 is land
        // 0 is water
        // beyond grid is also water

        // classic graph traversal
        // better to use dfs

        // steps
        // initialize the clone with 0
        vector<vector<int>> clone(m, vector<int>(n, 0));

        // start for all cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && clone[i][j] == 0) {
                    counte++;
                    dfs(grid, clone, i, j);
                }
            }
        }

        return counte;
    }
};
