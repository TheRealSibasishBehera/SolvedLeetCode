class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
    
    // vector<pair<int, int>> v;
    // for (int i = 0; i < nums.size(); i++)
    // {
        // v.push_back({nums[i], i});
    // }
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == target)
            return {i+1, j+1};
        else if (v[i]+ v[j] > target)
            j--;
        else
            i++;
    }

    return {-1, -1};
    }
};