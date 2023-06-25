class Solution {
public:
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum +=nums[i];
    }
    if(sum%2!=0) return false;
    return isSubsetSum(nums,sum/2);
    
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return helper(arr, sum, n - 1, dp);
}

bool helper(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
{
    // basecase
    if (sum == 0)
        return true;
    if (index == 0)
    {
        if (sum == arr[0])
        {
            return true;
        }
        return false;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];
    // take
    bool take = false;
    if (arr[index] <= sum)
        take = helper(arr, sum - arr[index], index - 1, dp);
    // not take
    bool notTake = false;
    notTake = helper(arr, sum, index - 1, dp);
    return dp[index][sum] = take || notTake;
}
};