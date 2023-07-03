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
    int mn = INT_MAX;
    TreeNode* prev;
    void dfs(TreeNode* root){
        if (!root) return;
         dfs(root->left);
        if (prev){
            mn = min(mn, root->val - prev->val);
        }
        prev = root;
       
        dfs(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return mn;
    }
};