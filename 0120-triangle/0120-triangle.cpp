class Solution {
public:
int helper(int i, int j,vector<vector<int>> &dp, vector<vector<int>> &triangle)
{
        if (dp[i][j] != -1)
        return dp[i][j];
    if (i >= triangle.size() || j >= triangle[triangle.size() - 1].size())
        return 0;
    
      if(i==triangle.size() - 1) return triangle[i][j];

    int up = 1e8, down = 1e8;
    up = helper(i + 1, j, dp, triangle) + triangle[i][j];
    down = helper(i + 1, j + 1, dp, triangle) + triangle[i][j];

    return dp[i][j] = min(up, down);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));


    return helper(0, 0, dp,triangle);
}
};