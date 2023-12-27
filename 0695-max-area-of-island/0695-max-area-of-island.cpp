class Solution {
public:
int maxi = 0;
int curr = 0;

void helper(vector<vector<int>> &grid, int i, int j, int m, int n)
{
    // base
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
    {
        return;
    }

    // unset if set
    grid[i][j] = 0;
    curr++;

    // explore other paths
    helper(grid, i + 1, j, m, n);
    helper(grid, i - 1, j, m, n);
    helper(grid, i, j - 1, m, n);
    helper(grid, i, j + 1, m, n);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // classic graph traversal
    // better to use dfs

    // start for all cells
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                curr = 0;
                helper(grid, i, j, m, n);
                maxi = max(maxi, curr);
            }
        }
    }

    return maxi;
}
};