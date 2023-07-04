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
    /*
            0
        1       0
    3
    
    */
    int coins = 0;
    int dfs(TreeNode* root){
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        coins += abs(l) + abs(r);
        return (l+r+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        int ans = dfs(root);
       
       
        return coins;
    }
};