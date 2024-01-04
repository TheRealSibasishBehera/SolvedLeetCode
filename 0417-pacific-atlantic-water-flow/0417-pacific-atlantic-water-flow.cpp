class Solution {
public:

void dfs(vector<vector<int>> &h, int i, int j, int m, int n, vector<vector<bool>> &can_reach, vector<vector<bool>> &vis, int pasth)
{
    // base
    if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || h[i][j] < pasth)
        return;

    vis[i][j] = true;
    can_reach[i][j] = true;

    dfs(h, i + 1, j, m, n, can_reach, vis, h[i][j]);
    dfs(h, i - 1, j, m, n, can_reach, vis, h[i][j]);
    dfs(h, i, j - 1, m, n, can_reach, vis, h[i][j]);
    dfs(h, i, j + 1, m, n, can_reach, vis, h[i][j]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    if (m == 0)
        return {};

    int n = heights[0].size();
    if (n == 0)
        return {};

    vector<vector<int>> ans;
    vector<vector<bool>> can_reach_pac(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_at(m, vector<bool>(n, false));
    vector<vector<bool>> vis_pac(m, vector<bool>(n, false));
    vector<vector<bool>> vis_at(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        dfs(heights, i, 0, m, n, can_reach_pac, vis_pac, 0);
        dfs(heights, i, n - 1, m, n, can_reach_at, vis_at, 0);
    }

    for (int j = 0; j < n; j++)
    {
        dfs(heights, 0, j, m, n, can_reach_pac, vis_pac, 0);
        dfs(heights, m - 1, j, m, n, can_reach_at, vis_at, 0);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (can_reach_pac[i][j] && can_reach_at[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}
};