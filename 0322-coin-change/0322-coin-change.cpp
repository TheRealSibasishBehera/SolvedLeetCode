class Solution
{
public:
    int helper(int n, int w, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 1e8;
        // if (n == 1)
        // {
        //     if (w % coins[0] == 0)
        //         return w / coins[0];
        //     else
        //         return 1e8;
        // }
        if (w == 0)
            return 0;
        if (dp[n][w] != -1)
            return dp[n][w];

        int pick = 1e8, not_pick = 1e8;
        if (w - coins[n - 1] >= 0)
            pick = 1 + helper(n, w - coins[n - 1], coins, dp);
        not_pick = helper(n - 1, w, coins, dp);

        return dp[n][w] = min(pick, not_pick);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int w = amount;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        int x = helper(n, w, coins, dp);
        return (x < 1e8) ? x : -1;
    }
};