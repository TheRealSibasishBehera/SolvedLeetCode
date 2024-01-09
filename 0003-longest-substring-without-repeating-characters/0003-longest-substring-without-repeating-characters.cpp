class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) return 0;
        int start = 0;
        int n = s.size();
        int maxi = INT_MIN;
        unordered_map<char, int> sete;  // Use unordered_map to store characters and their indices
        for (int i = 0; i < n; i++)
        {
            if (sete.find(s[i]) != sete.end())
            {
                maxi = max(maxi, i - start);
                start = max(start, sete[s[i]] + 1);
            }
            sete[s[i]] = i;  // Store character and its index in the map
        }

        // Check for the last substring
        maxi = max(maxi, n - start);

        return maxi;
    }
};
