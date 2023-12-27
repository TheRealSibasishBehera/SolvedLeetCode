
class Solution {
public:
    vector<vector<string>> ans;

    bool checkPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void helper(string &s, int start, vector<string> &temp)
    {
        if (start == s.size())
        {
            ans.push_back(temp);
            return;
        }

        // eg "aab"
        //[["a","a","b"],["aa","b"]]

        for (int i = start; i < s.size(); i++) // Change the loop condition here
        {
            if (checkPalindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, temp);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s)
    {
        // basically divide them into parts such that it's contiguous
        // and each part is a palindrome
        vector<string> temp;
        helper(s, 0, temp);

        return ans;
    }
};


