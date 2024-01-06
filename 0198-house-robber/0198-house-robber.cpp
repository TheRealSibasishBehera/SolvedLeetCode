
class Solution
{
public:
    int helper(int index, vector<int> &nums, vector<int> &dp)
    {
        // pick this one and go to index -2
        // or dont picj and go to index-1
        if (index < 0)
            return 0;
        if (index == 0)
            return nums[index];

        if (dp[index] != -1)
            return dp[index];
            
        int pick = nums[index] + helper(index - 2, nums, dp);
        int not_pick = helper(index - 1, nums, dp);
        return dp[index] = max(pick, not_pick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        return helper(n - 1, nums, dp);
    }
};