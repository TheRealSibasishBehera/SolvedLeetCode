#include <climits>

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool helper(TreeNode* root, long long l, long long r) {
        if (!root)
            return true;

        int x = root->val;

        if (x <= l || x >= r)
            return false;

        return helper(root->left, l, x) && helper(root->right, x, r);
    }
};
