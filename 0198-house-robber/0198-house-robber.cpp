class Solution
{
public:
int rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0) {
        return 0; // No houses to rob
    }

    if (n == 1) {
        return nums[0]; // Only one house, so rob it
    }

    int prev = 0;
    int prev2 = nums[0];
    int curr = 0;
    
    for (int i = 1; i < n; i++)
    {
        int x = nums[i] + prev;
        int y = prev2;
        curr = max(x, y);

        prev = prev2;
        prev2 = curr;
    }

    return curr;
}


};