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
    int depth(TreeNode* root){
        if (!root) return 0;
        if (!root->left || !root->right){
            int a =  root->left ? depth(root->left) : depth(root->right);
            return 1 + a;
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        return depth(root);
    }
};