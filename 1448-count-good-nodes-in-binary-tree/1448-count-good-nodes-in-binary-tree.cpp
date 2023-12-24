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
    int counti = 0; // Initialize counti to 0
    int maxi = INT_MIN; // Initialize maxi to the minimum possible integer value

    void helper(TreeNode* node) {
        if (!node)
            return;

        int x = node->val;
        if (x >= maxi)
            counti++;

        maxi = max(x, maxi);
        int prev = maxi;

        helper(node->right);

        // restore maxi value;
        maxi = prev;

        helper(node->left);
        // return counti a+b;
    }

    int goodNodes(TreeNode* root) {
        // looks like a dfs question
        if (!root)
            return 0;

        int maxi = root->val; // Initialize maxi with the value of the root node
        helper(root);
        return counti;
    }
};