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
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    void dfs(TreeNode* root, vector<vector<string>>&res, int r, int c, int h){
        if (!root) return;
        res[r][c] = to_string(root->val);
        dfs(root->left, res, r+1, c - pow(2,h-r-1), h);
        dfs(root->right,res,r+1,c+pow(2,h-r-1),h);
        
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = depth(root) - 1;
        int m = height + 1;
        int n = pow(2,m) - 1;
        vector<vector<string>>res(m, vector<string>(n,""));
        int r = 0, c = (n-1)/2;
        dfs(root,res,r,c,height);
        return res;
    }
};