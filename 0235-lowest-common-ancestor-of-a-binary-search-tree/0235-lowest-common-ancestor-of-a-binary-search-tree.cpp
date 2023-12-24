/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        int x = p->val;
        int y = q->val;
        int z = root->val;

        if (z > y && z > x)
            root = root->left;

        else if (z < y && z < x)
            root = root->right;

        else
            return root;
    }

    return nullptr; // If no common ancestor is found
}
};