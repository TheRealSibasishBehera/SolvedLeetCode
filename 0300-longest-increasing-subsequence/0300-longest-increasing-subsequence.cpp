class Solution
{
public:
    int helper(int lastIdx, vector<int> &nums, int index, vector<vector<int>> &dp)
    {
        // base case
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][lastIdx+1] != -1)
        {
            return dp[index][lastIdx+1];
        }

        int pick = 0, notPick = 0;

        // not pick
        notPick = helper(lastIdx, nums, index + 1, dp);

        // pick
        if (lastIdx == -1 || nums[index] > nums[lastIdx])
        {
            pick = 1 + helper(index, nums, index + 1, dp);
        }

        // maximum of pick and not pick
        int result = max(pick, notPick);
        return dp[index][lastIdx+1] = result;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        return helper(-1, nums, 0, dp);
    }
};