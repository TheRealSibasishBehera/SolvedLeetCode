class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::vector<int> count(26, 0); // Assuming only lowercase English letters

        for (auto &x : s1) {
            count[x - 'a']++;
        }

        std::vector<int> copy = count;
        int windowSize = s1.size();
        int i = 0, j = 0;

        while (j < s2.size()) {
            if (countEmpty(count)) {
                // std::cout << i << " " << s2[i] << " " << s2[i] << " " << j << std::endl;
                return true;
            }

            // Check if s2[j] is a valid lowercase English letter
            if (s2[j] >= 'a' && s2[j] <= 'z') {
                // if not found, reset the window by keeping count as copy again and moving to the next character
                if (count[s2[j] - 'a'] == 0) {
                    count = copy;
                    i = j = i + 1;
                } else {
                    count[s2[j] - 'a']--;
                    j++;
                }
            } else {
                // If s2[j] is not a valid lowercase English letter, move to the next character
                j++;
            }
        }

        return countEmpty(count);
    }

private:
    bool countEmpty(const std::vector<int>& count) {
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }
};