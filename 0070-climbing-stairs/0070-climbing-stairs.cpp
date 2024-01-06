class Solution
{
public:
    int climbStairs(int n)
    {
                if(n==1){return 1;}
        if(n==0){return 1;}
        int prev = 0;
        int prev2 = 1;
        int curr = 0;
        // iterative soln
        for (int i = 1; i <= n; i++)
        {

            curr = prev + prev2;
            prev = prev2;
            prev2 = curr;
            
        }
        return curr;
    }
};