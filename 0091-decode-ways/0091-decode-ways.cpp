class Solution
{
public:
    int helper(int index, string s, int n, vector<int> &dp)
    {
        if (index >= s.size())
            return 1;

        if (dp[index] != -1)
            return dp[index];

        int pick = 0, not_pick = 0;

        int x = stoi(s.substr(index, 1));
        if (x >= 1 && x <= 9)
            pick = helper(index + 1, s, n, dp);

        if (index + 1 < n)
        {
            x = stoi(s.substr(index, 2));

            if (x >= 10 && x <= 26)
                not_pick = helper(index + 2, s, n, dp);
        }

        return dp[index] = pick + not_pick;
    }
    int numDecodings(string s)
    {
        // obs
        // basically while decoding u can take 1 or 2 digits at a time
        int n = s.size();
        vector<int> dp(n,-1);
        return helper(0,s, n, dp);
    }
};
