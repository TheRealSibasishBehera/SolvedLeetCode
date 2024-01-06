class Solution
{
public:
    int helper(vector<int> &cost, int sizee , vector<int> &dp)
    {
        if (sizee == 1 || sizee == 0)
        {
            return dp[sizee]= cost[sizee];
        }

        if(dp[sizee]!= -1) return dp[sizee];
        return dp[sizee] = cost[sizee] + min(helper(cost, sizee - 1 , dp), helper(cost, sizee - 2,dp));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int sizee = cost.size();
        vector<int> dp (sizee+2, -1);
        return min(helper(cost, sizee - 1, dp), helper(cost, sizee - 2, dp));
    }
};