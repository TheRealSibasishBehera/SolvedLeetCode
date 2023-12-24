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
vector<int> v;
    int ke=0;
void helper(TreeNode *root) 
{
    if(!root) return ;
    if(ke==v.size()) return ;
    helper(root->left);
    v.push_back(root->val);
    helper(root->right);
}
int kthSmallest(TreeNode *root, int k)
{
    ke=k;
    helper(root);
    return v[k-1];
}
};