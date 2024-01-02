class Solution
{
public:
    int count = 0;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            count++;
            return;
        }

        if (visited[i][j] == 1)
            return;
        visited[i][j] = 1;

        dfs(i + 1, j, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, visited);
                }
            }
        }
        
        return count;
    }
};