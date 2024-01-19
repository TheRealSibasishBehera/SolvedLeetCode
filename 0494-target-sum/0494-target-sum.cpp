class Solution {
public:
    int helper(int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
        // base condition
        if (n == 1) {
            if (k == 0 && arr[0] == 0) return 2;
            if (k == 0 || k == arr[0]) return 1;
            return 0;
        }
        if (n == 0) {
            return (k == 0) ? 1 : 0;
        }

        if (dp[n][k] != -1)
            return dp[n][k];
        int pick = 0, not_pick = 0;
        if (k - arr[n - 1] >= 0)
            pick = helper(n - 1, k - arr[n - 1], arr, dp);
        not_pick = helper(n - 1, k, arr, dp);

        return dp[n][k] = pick + not_pick;
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If the sum is odd or target is too large, there is no way to achieve the target.
        if (sum < target || (sum + target) % 2 != 0) {
            return 0;
        }

        int k = (sum + target) / 2;
            if(k<0) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(n, k, nums, dp);
    }
};
