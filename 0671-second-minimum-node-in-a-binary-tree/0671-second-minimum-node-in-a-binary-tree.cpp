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
    bool flag = false;
    void dfs(TreeNode* root, int& k, int& ans){
        if (!root) return;
        if (root->val > k){
            mn = min(mn,root->val);
            flag = true;
        }
        dfs(root->left,k,ans);
        dfs(root->right,k,ans);    
        return;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int k = root->val;
        int ans = -1;
        dfs(root,k,ans);
        return flag == false ? -1 : mn;
    }
};