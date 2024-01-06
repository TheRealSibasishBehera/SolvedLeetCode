class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int sizee = cost.size();
        vector<int> dp(sizee + 2, -1);
        // we will do it using iteratively
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < sizee; i++)
        {
            dp[i]  = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[sizee-1], dp[sizee-2]);
    }
};