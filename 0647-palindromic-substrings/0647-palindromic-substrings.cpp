class Solution
{
public:
    int countSubstrings(string s)
    {
        string res = "";
        int resLen = 0;
        string maxi = "";
        int count =0;
        // check all odd length possibilities
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            l = i, r = i;
            while (l >= 0 && r <= s.size() - 1 && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }

            // Update res and maxi after the loop
            res = s.substr(l + 1, r - l - 1);
            if (resLen < r - l - 1)
            {
                resLen = r - l - 1;
                maxi = res;
            }
        }

        // Check all even length possibilities
        for (int i = 0; i < s.size(); i++)
        {
            l = i, r = i + 1;
            while (l >= 0 && r <= s.size() - 1 && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }

            // Update res and maxi after the loop
            res = s.substr(l + 1, r - l - 1);
            if (resLen < r - l - 1)
            {
                resLen = r - l - 1;
                maxi = res;
            }
        }

        return count;
    }
};