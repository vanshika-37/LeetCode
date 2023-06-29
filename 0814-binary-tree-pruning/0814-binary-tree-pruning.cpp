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
    void dfs(TreeNode* &root){
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        if (root->val != 1){
            if (!root->left and !root->right) root = NULL;
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};