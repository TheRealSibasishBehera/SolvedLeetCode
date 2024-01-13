class Solution
{
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        // base case
        if (i == 0 && j == 0)
            return 1;

        // could not be reached
        if (i < 0 || j < 0)
            return 0;

        // check if already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int x = 0;
        int y = 0;
        x = helper(i, j - 1, m, n, dp);
        y = helper(i - 1, j, m, n, dp);
        return dp[i][j] = x + y;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, m, n, dp);
    }
};