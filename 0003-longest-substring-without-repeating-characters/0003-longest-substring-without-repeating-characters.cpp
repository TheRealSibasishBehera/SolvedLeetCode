class Solution {
public:
 int lengthOfLongestSubstring(string s)
{
    int ans = 1;
    if (s.length() == 0)
        return 0;
    int l = 0;
    int r = 0;
    int maxi = INT_MIN;

    int curr = 0;

    unordered_set<char> st;
    while (r < s.length())
    {
        if (st.find(s[r]) == st.end())
        {
            // implies element is not present
            st.insert(s[r]);
        }
        else{
            // element is present
            while (st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
        }
        maxi = max(maxi, r - l + 1);
        r++;
        
    }

    return maxi;
}
};