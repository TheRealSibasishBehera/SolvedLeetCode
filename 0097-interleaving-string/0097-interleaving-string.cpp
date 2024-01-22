#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();

        if (m + n != o) {
            return false;  // Length mismatch, s3 cannot be an interleaving of s1 and s2
        }

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return isInterleaveRecursive(s1, s2, s3, 0, 0, 0, memo);
    }

private:
    bool isInterleaveRecursive(const string& s1, const string& s2, const string& s3,
                               int i, int j, int k, vector<vector<int>>& memo) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i < s1.size() && s1[i] == s3[k]) {
            if (isInterleaveRecursive(s1, s2, s3, i + 1, j, k + 1, memo)) {
                return memo[i][j] = true;
            }
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            return memo[i][j] = isInterleaveRecursive(s1, s2, s3, i, j + 1, k + 1, memo);
        }

        return memo[i][j] = false;
    }
};

