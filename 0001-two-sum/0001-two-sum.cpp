#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> sete;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (sete.find(diff) != sete.end()) {
                // If complement found, return the indices
                return {sete[diff], i};
            }

            // Add the current element to the sete map
            sete[nums[i]] = i;
        }

        // No solution found
        return {-1, -1};
    }
};
