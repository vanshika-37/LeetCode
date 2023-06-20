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
    int solve(TreeNode* root, int &maxi){
        if (!root) return 0;
        int lst = max(0,solve(root->left, maxi));
        int rst = max(0,solve(root->right, maxi));
        maxi = max(maxi, root->val + lst + rst);
        return root->val + max(lst,rst);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = solve(root,maxi);
        return maxi;
        
    }
};
