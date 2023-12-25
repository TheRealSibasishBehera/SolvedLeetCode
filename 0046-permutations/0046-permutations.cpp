class Solution {
public:
vector<vector<int>> ans;

void helper(vector<int> &nums, int start, vector<vector<int>> &result)
{
    // real math solution
    // is make a iteration through all element
    // pop that specific element , its now a array of size(prev_size-1) make a call
    // put them back in
    // base - length is 1

    // but in cpp u cant pop , so we have to use some logic with swapping
    //
    // 1 2 3

    // call 1 2 3 -> s=1 -> call 1 2 3 , call 1 3 2
    // call 2 1 3 -> s=1 -> call 2 1 3 , call 2 3 1
    // call 3 2 1 -> s=1 -> call 3 2 1 , call 3 1 2
    // base
    if (start == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        helper(nums, start + 1, result);
        swap(nums[i], nums[start]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> temp;
    helper(nums, 0, temp);
    return temp;
}
};