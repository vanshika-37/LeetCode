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
    void dfs(TreeNode*& root, int& val, TreeNode*& n){
        if (!root){
            root = n;
            return;
        }
        if (root->val < val){
            n->left = root;
            root = n;
            return;
        }
        dfs(root->right,val,n);
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* n = new TreeNode(val);
        dfs(root,val,n);
        return root;
    }
};