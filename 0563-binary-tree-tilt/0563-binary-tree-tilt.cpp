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
    int res= 0;
    int dfs(TreeNode* &root){
        if (!root) return 0;
        int lst = dfs(root->left);
        int rst = dfs(root->right);
        int ans = abs(lst - rst);
        res += ans;
        return root->val + lst + rst;
    }
    
    int findTilt(TreeNode* root) {
        int a = dfs(root);
        return res;
    }
};