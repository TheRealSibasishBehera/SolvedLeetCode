class Solution
{
public:
    bool helper(int i, string s, vector<string> &wordDict, vector<int> &dp)
    {
        if (i == s.length())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (const string &word : wordDict)
        {
            int l = word.size();
            if (i + l <= s.length() && s.substr(i, l) == word)
            {
                if (helper(i + l, s, wordDict, dp))
                    return dp[i] = 1;
            }
        }

        dp[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);
        return helper(0, s, wordDict, dp);
    }
};
