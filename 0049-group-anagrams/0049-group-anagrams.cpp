class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mpp;
    for (int i = 0; i < strs.size(); i++)
    {
       string key = strs[i];
       ranges::sort(key);

       mpp[key].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto x : mpp)
    {
        ans.push_back(x.second);
    }

    return ans;
    

}
};