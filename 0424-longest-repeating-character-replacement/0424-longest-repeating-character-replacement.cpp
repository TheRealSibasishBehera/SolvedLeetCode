class Solution {
public:

std::unordered_map<char, int> mpp;

char max_ele() {
    char maxi = '\0';  // Initialize maxi with a default character
    int maxCount = 0;
    for (const auto &x : mpp) {
        if (x.second > maxCount) {
            maxCount = x.second;
            maxi = x.first;
        }
    }
    return maxi;
}

int characterReplacement(std::string s, int k) {
    int l = 0;
    int ans = 0;
    char maxi = '\0';

    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
        if (mpp[s[i]] > mpp[maxi])
            maxi = s[i];

        // check valid
        bool valid = ((i - l + 1) - mpp[maxi] <= k);
        if (valid)
            ans = std::max(ans, (i - l + 1));
        else {
            // we need to change window
            mpp[s[l]]--;
            maxi = max_ele();
            l++;
        }
    }

    return ans;
}

};