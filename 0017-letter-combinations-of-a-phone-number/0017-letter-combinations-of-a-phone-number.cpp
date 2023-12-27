class Solution {
public:

std::unordered_map<int, std::vector<char>> mpp;
std::vector<std::string> ans;

void helper(const std::string& d, std::string curr, int i) {
    if (i == d.size()) {
        ans.push_back(curr);
        return;
    }

    for (char j : mpp[d[i] - '0']) {
        curr += j;
        helper(d, curr, i + 1);
        curr.pop_back();
    }
}

std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) {
        return ans; // Return an empty vector for an empty input
    }

    mpp[2] = {'a', 'b', 'c'};
    mpp[3] = {'d', 'e', 'f'};
    mpp[4] = {'g', 'h', 'i'};
    mpp[5] = {'j', 'k', 'l'};
    mpp[6] = {'m', 'n', 'o'};
    mpp[7] = {'p', 'q', 'r', 's'};
    mpp[8] = {'t', 'u', 'v'};
    mpp[9] = {'w', 'x', 'y', 'z'}; // Corrected 'q' to 'w'

    std::string curr = "";
    helper(digits, curr, 0);
    return ans;
}

};