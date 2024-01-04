class Solution {
public:

void dfs(vector<vector<int>> &h, int i, int j, int m, int n, vector<vector<bool>> &can_reach, int pasth, bool isPacific)
{
    // base
    if (i < 0 || j < 0 || i >= m || j >= n)
        return;

    if (h[i][j] < pasth || can_reach[i][j])
        return;

    can_reach[i][j] = true;

    dfs(h, i + 1, j, m, n, can_reach, h[i][j], isPacific);
    dfs(h, i - 1, j, m, n, can_reach, h[i][j], isPacific);
    dfs(h, i, j - 1, m, n, can_reach, h[i][j], isPacific);
    dfs(h, i, j + 1, m, n, can_reach, h[i][j], isPacific);
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

    for (int i = 0; i < m; i++)
    {
        dfs(heights, i, 0, m, n, can_reach_pac, INT_MIN, true);
        dfs(heights, i, n - 1, m, n, can_reach_at, INT_MIN, false);
    }

    for (int j = 0; j < n; j++)
    {
        dfs(heights, 0, j, m, n, can_reach_pac, INT_MIN, true);
        dfs(heights, m - 1, j, m, n, can_reach_at, INT_MIN, false);
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