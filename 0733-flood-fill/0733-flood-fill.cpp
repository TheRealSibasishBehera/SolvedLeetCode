
class Solution
{
public:
    int m = 0;
    int n = 0;
    int start = 0;
   vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>> &grid, int x, int y, int color)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != start || grid[x][y] == color)
        {
            return;
        }

        grid[x][y] = color;

        for (const auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            dfs(grid, newX, newY, color);
        }
    }

   vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int color)
    {
        m = grid.size();
        n = grid[0].size();
        start = grid[sr][sc];

        if (start == color)
        {
            return grid;
        }

        dfs(grid, sr, sc, color);
        return grid;
    }
};
