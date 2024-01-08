class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string is always a valid word break

        for (int i = 1; i <= n; ++i)
        {
            for (string word : wordDict)
            {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word)
                {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }

        return dp[n];
    }
};
