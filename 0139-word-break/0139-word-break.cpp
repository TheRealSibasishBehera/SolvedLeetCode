class Solution
{
public:
    bool helper(int i, string s, vector<string> &wordDict, vector<bool> &dp)
    {
        if (i == s.length())
            return true;

        if (dp[i])
            return false;

        for (const string &word : wordDict)
        {
            int l = word.size();
            if (i + l <= s.length() && s.substr(i, l) == word)
            {
                if (helper(i + l, s, wordDict, dp))
                    return true;
            }
        }

        dp[i] = true;
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size());
        return helper(0, s, wordDict, dp);
    }
};
