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
    pair<int,int>dfs(TreeNode* root){
        if (!root) return make_pair(0,0);
        pair<int,int>l = dfs(root->left);
        pair<int,int>r = dfs(root->right);
        int take = root->val + l.second + r.second;
        int notTake = max(l.first,l.second) + max(r.first,r.second);
        return make_pair(take, notTake);
    }
    
    int rob(TreeNode* root) {
        pair<int,int>a = dfs(root);
        return max(a.first,a.second);
    }
};