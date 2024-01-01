class Solution {
public:
// basic obs
// at each point the water trapped is min(left_max, right_max) - height[i]
int trap(vector<int> &height)
{
    vector<int> left_max(height.size());
    vector<int> right_max(height.size());
    left_max[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        left_max[i] = max(left_max[i - 1], height[i - 1]);
    }
    right_max[height.size() - 1] = 0;
    for (int i = height.size() - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], height[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int water = min(left_max[i], right_max[i]) - height[i];
        if (water > 0)
            ans += water;
    }

    return ans;
    
}
};