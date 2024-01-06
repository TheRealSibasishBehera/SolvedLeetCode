class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int sizee = cost.size();
        // Initialize x and y with the costs of the first two steps
        int x = cost[0];
        int y = cost[1];
        
        for (int i = 2; i < sizee; i++)
        {
            int curr = cost[i] + min(x, y);
            x = y;
            y = curr;
        }

        return min(x, y);
        // The minimum cost to reach the top is either from the last step or the second-to-last step
    }
};
