
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int x = nums[i], y = INT_MIN;
            if (i - 2 >= 0)
                x += dp[i - 2];
            y = dp[i - 1];
            dp[i] = max(x, y);
        }

        return dp[n - 1];
    }
};