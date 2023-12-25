class Solution {
public:

vector<vector<int>> ans; // Assuming this is declared somewhere in your code

void helper(vector<int> &nums, int index, vector<int> &temp, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    if (index == nums.size() || target < 0)
    {
        return;
    }

    temp.push_back(nums[index]);
    helper(nums, index, temp, target - nums[index]);
    temp.pop_back();
    helper(nums, index + 1, temp, target);

    return;
}

vector<vector<int>> combinationSum(vector<int> &a, int target)
{
    vector<int> temp;
    helper(a, 0, temp, target);

    return ans;
}


};