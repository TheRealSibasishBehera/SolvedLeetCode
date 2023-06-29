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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
    
    void helper(TreeNode* node , vector<int>& v) {
        if(node == NULL ) return ;
        if(node->left)  helper(node->left,v);
        if(node->right)  helper(node->right,v);
        v.push_back(node->val);
        
        return ;
    }
};