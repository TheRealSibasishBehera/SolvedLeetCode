
class Solution {
public:
    std::vector<std::string> ans;

    void helper(int n, int cl, int op, string& current) {
        // base case
        if (op == n && cl == n) {
            ans.push_back(current);
            return;
        }

        // 2 cases
        // push open
        if (op < n) {
            current.push_back('(');
            helper(n, cl, op + 1, current);
            current.pop_back();
        }

        // push close
        if (cl < n && cl < op) {
            current.push_back(')');
            helper(n, cl + 1, op, current);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        helper(n, 0, 0, current);
        return ans;
    }
};
