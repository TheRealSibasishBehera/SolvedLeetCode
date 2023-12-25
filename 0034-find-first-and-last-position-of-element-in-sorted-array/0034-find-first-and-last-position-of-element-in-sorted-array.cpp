class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int middle;
        int ans = -1;
        vector<int> res;

        // Find the first index
        while (l <= r) {
            middle = l + (r - l) / 2;
            if (nums[middle] == target) {
                ans = middle;
                r = middle - 1;
            } else if (nums[middle] < target) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }
        if (ans == -1) {
            // Target not found
            return {-1, -1};
        }
        res.push_back(ans);

        // Find the last index
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            middle = l + (r - l) / 2;
            if (nums[middle] == target) {
                ans = middle;
                l = middle + 1;
            } else if (nums[middle] < target) {
                l = middle + 1;
            } else {
                r = middle - 1;
            }
        }
        res.push_back(ans);

        return res;
    }

};