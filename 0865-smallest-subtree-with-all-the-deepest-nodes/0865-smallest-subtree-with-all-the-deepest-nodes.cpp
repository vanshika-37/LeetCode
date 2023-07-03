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
    
    void dfs(TreeNode* root, int& d, int h, vector<TreeNode*>&ans){
        if (!root) return;
        if (h == d){
            ans.push_back(root);
        }
        dfs(root->left,d,h+1,ans);
        dfs(root->right,d,h+1,ans);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return NULL;
        if (root == p || root == q) return root;
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right,p,q);
        if (l and r) return root;
        if (root->left == NULL and root->right == NULL) return NULL;
        return l == NULL ? r : l;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = depth(root);
        int h = 1;
        vector<TreeNode*>ans;
        dfs(root,d,h,ans);
        TreeNode* n = ans[0];
        for (int i = 1; i < ans.size(); i++){
            n = lca(root,n,ans[i]);
        }
        return n;
    }
};