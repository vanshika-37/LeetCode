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
    int ld(TreeNode *root){
        if (!root) return 0;
        return 1 + ld(root->left);
    }
    int rd(TreeNode *root){
        if (!root) return 0;
        return 1 + rd(root->right);
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = ld(root);
        int rh = rd(root);
        if (lh == rh){
            return pow(2,lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};