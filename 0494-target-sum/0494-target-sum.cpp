class Solution
{
public:
    int offset = 1001;
    map<pair<int, int>, int> dp;

    int helper(int target, vector<int> &nums, int index, int count)
    {
        // base case
        if (index < 0)
        {
            return (target == 0) ? 1 : 0;
        }

        if (dp.find({index, target}) != dp.end())
        {
            return dp[{index, target}];
        };
        // either u can add or subtract
        int x = 0,
            y = 0;
        x = helper(target - nums[index], nums, index - 1, count);
        y = helper(target + nums[index], nums, index - 1, count);

        return dp[{index, target}] = x + y;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // meed to include negative numbers
        // vector<vector<int>> dp(offset * 2, vector<int>(nums.size() + 1, -1));
        return helper(target, nums, nums.size() - 1, 0);
    }
};