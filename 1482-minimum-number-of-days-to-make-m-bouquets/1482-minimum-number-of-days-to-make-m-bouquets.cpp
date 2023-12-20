class Solution {
public:
    bool check2(vector<int> &nums, int m, int k, int mid) {
        vector<int> temp = nums;
        int flowers = 0;
        int bouq = 0;
        
        for (int i = 0; i < temp.size(); i++) {
            int newe = nums[i] - mid;
            if (newe <= 0) {
                temp[i] = 0;
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 0) {
                flowers++;
                if (flowers == k) {
                    bouq++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouq >= m;
    }

    int minDays(vector<int> &nums, int m, int k) {
        long long int si = nums.size();
        long long int mcrk = static_cast<long long int>(m) * k;
        if (si < mcrk) return -1;

        int start = 0;
        int end = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check2(nums, m, k, mid)) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
