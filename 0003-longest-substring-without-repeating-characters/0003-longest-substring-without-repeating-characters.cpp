class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        int start = 0;
        int n = s.size();
        int maxi = INT_MIN;
        unordered_map<char, int> sete; // Use unordered_map to store characters and their indices

        int l = 0, r = 0;
        while (r < s.size())
        {
            // check the element
            if (sete.find(s[r]) != sete.end())
            {
                l = max(sete[s[r]] + 1, l); // Update l only if it's greater than the current l
            }

            sete[s[r]] = r;
            r++;
            maxi = max(maxi, r - l); // Update maxi here to consider the current substring length
        }

        return maxi;
    }
};
