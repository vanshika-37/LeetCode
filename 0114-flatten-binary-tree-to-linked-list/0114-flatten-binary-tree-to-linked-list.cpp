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
    void preorder(TreeNode *root, vector<int>&ans){
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    void flatten(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        for (int i = 1; i < ans.size(); i++){
            TreeNode *r = new TreeNode(ans[i]);
            root->right = r;
            root->left = NULL;
            root = root->right;
        }
    }
};