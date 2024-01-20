class Solution
{
public:
    int helper(int n, int w, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 0;

        if (w == 0)
            return 1;
        if (dp[n][w] != -1)
            return dp[n][w];

        int pick = 0, not_pick = 0;
        if (w - coins[n - 1] >= 0)
            pick = helper(n, w - coins[n - 1], coins, dp);
        not_pick = helper(n - 1, w, coins, dp);

        return dp[n][w] = pick+ not_pick;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int w = amount;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        int x = helper(n, w, coins, dp);
        return x;
    }
};