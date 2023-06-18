class Solution {
public:
int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if(i<0 || j<0) return 0;
    // base case is out of bounds
    if (i == 0 && j == 0) return obstacleGrid[i][j];
    int up = 1e8, down = 1e8;
        if(i>0)up = helper(i - 1, j, dp, obstacleGrid)+obstacleGrid[i][j];
        if(j>0)down = helper(i, j - 1, dp, obstacleGrid)+obstacleGrid[i][j];

    return  dp[i][j]=min(up,down);
}
int minPathSum(vector<vector<int>> &grid)
{


    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];

            else
            {
                int up = 1e8, down = 1e8;
                 if (i > 0) up = dp[i-1][j]+grid[i][j];
               if (j > 0)  down = dp[i][j-1]+grid[i][j];
                dp[i][j] = min(up, down);
            }
        }
    }

    return dp[m-1][n-1];
}
};