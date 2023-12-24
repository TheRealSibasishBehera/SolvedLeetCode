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
    int x = p->val;
    int y = q->val;
    int z = root->val;
    // find a node such that , one is greater than and one is smaller

    if (z > y && z > x)
        return lowestCommonAncestor(root->left, p, q);

    else if (z < y && z < x)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}
};