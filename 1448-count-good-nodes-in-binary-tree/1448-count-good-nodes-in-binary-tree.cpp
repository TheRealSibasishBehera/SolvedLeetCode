/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }

private:
    int helper(TreeNode* node, int maxi) {
        if (!node)
            return 0;

        int x = node->val;
        int counti = (x >= maxi) ? 1 : 0;

        maxi = std::max(x, maxi);

        int countLeft = helper(node->left, maxi);
        int countRight = helper(node->right, maxi);

        return counti + countLeft + countRight;
    }
};