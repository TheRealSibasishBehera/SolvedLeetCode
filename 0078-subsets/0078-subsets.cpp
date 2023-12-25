class Solution {
public:
    vector<vector<int>> ans;

void helper(vector<int> &nums, int index, vector<int> &temp)
{
    if (index == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    helper(nums, index + 1, temp);
    temp.pop_back();
    helper(nums, index + 1, temp);

    return;
}
vector<vector<int>> subsets(vector<int> &a)
{
    sort(a.begin(), a.end());
    vector<int> temp;
    helper(a, 0,temp);

    return ans;
}
};