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
    int mx = INT_MIN;
    int depth(TreeNode* root){
        if (!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        mx = max(mx, 1 + l + r);
        return 1 + max(l,r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = depth(root);
        return mx - 1;
    }
};