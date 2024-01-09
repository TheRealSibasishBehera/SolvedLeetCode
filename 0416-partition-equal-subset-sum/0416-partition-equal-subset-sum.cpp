class Solution
{
public:
    bool helper(int target, vector<int> &nums, int index, vector<vector<int>> &dp)
    {
        // base case
        if (index < 0)
            return false;
        if (target == 0)
            return true;
        if (target < 0)
            return false;

        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool pick = false;
        bool not_pick = false;

        // pick
        if (target > 0)
            pick = helper(target - nums[index], nums, index - 1, dp);

        // not pick
        not_pick = helper(target, nums, index - 1, dp);

        dp[index][target] = pick || not_pick;

        return dp[index][target];
    }

    bool canPartition(vector<int> &nums)
    {
        // sub set partiation
        // find set with partiation /2
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
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(target, nums, nums.size() - 1, dp);
    }
};