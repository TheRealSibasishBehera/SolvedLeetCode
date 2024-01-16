class Solution
{
public:
    int helper(int n, int target, vector<int> &nums, vector<unordered_map<int, int>> &dp)
    {
        if (n == 0)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[n].find(target) != dp[n].end())
            return dp[n][target];
        int add = 0, sub = 0;
        add = helper(n - 1, target + nums[n - 1], nums,dp);
        sub = helper(n - 1, target - nums[n - 1], nums,dp);
        return dp[n][target] = add + sub;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        return helper(n, target, nums, dp);
    }
};