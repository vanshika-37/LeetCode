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
    vector<int>in;
    void dfs(TreeNode* root){
        if (!root) return;
        dfs(root->left);
        in.push_back(root->val);
        dfs(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int mn = INT_MAX, curr = INT_MAX;
        for (int i = 0; i < in.size()-1; i++){
            curr = in[i+1] - in[i];
            mn = min(mn,curr);
        }
        return mn;
    }
};