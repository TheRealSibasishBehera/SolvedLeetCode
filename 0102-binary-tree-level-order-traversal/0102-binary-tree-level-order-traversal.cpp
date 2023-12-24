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
vector<vector<int>> levelOrder(TreeNode *root)
{
    // classic bfs traversal
    vector<vector<int>> ans;
    queue<pair<TreeNode *, int>> q;
    int count = 0;
    if (root)
        q.push({root, 0});

    while (!q.empty())
    {
        TreeNode *node = q.front().first;
        int level = q.front().second;
        q.pop();

        if (ans.size() <= level)
        {
            ans.push_back({});
        }
        ans[level].push_back(node->val);
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }

    return ans;
}
};