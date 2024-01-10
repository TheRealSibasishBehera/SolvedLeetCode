#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].first = position[i];
            arr[i].second = speed[i];
        }

        // Sort in descending order based on positions
        sort(arr.begin(), arr.end(), greater<std::pair<int, int>>());

        vector<double> st;

        for (int i = 0; i < n; i++) {
            // Calculate time to reach the target for each car
            st.push_back((target - arr[i].first) / static_cast<double>(arr[i].second));

            if (st.size() > 1 && st[st.size() - 1] <= st[st.size() - 2]) {
                st.pop_back();
                // Merge fleets if the current car will meet the previous one
            }
        }

        return st.size();
    }
};
