class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // sub set partition
        // find set with partition /2
        int sum = 0;
        for (auto &x : nums)
        {
            sum += x;
        }

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = nums.size();

        // dp[i][j] represents whether there's a subset of nums[0..i] that can add up to j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        // base condition
        // if target == 0 return true
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // for index <0 we have to return 0
        for (int t = 0; t <= target; t++)
        {
            dp[0][t] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool x = false, y = false;

                if (j - nums[i - 1] >= 0)
                    x = dp[i - 1][j - nums[i - 1]];

                y = dp[i - 1][j];

                dp[i][j] = x || y;
            }
        }

        return dp[n][target];
    }
};
