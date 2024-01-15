class Solution
{
public:
    // in this problem if u want to use the > sign u have to start from o going over to the endq
    int helper(int last, int index, vector<int> &nums, vector<vector<int>> &dp)
    {
        // base case
        if (index == nums.size())
        {
            return 0;
        }
        int take = INT_MIN, not_take = INT_MIN;
        if (dp[last + 1][index] != -1)
        {
            return dp[last + 1][index];
        }

        if (last==-1 || nums[index] > nums[last] )
        {
            take = 1 + helper(index, index + 1, nums, dp);
        }
        not_take = helper(last, index + 1, nums, dp);
        // 2 cases u can take and not take
        return dp[last + 1][index] = max(take, not_take);

    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return helper(-1, 0, nums, dp);
    }
};