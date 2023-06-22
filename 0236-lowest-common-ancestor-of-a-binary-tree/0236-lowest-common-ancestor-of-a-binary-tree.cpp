/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, vector<TreeNode*>& ans, TreeNode* k){
        if (!root) return false;
        ans.push_back(root);
        if (root->val == k->val) return true;
        if(solve(root->left,ans,k) || solve(root->right,ans,k)) return true;
        ans.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1, ans2;
        solve(root,ans1,p);
        solve(root,ans2,q);
        int i = 0, j = 0;
        while(i < ans1.size() and j < ans2.size()){
            if (ans1[i] != ans2[j]){
                break;
            }
            i++;
            j++;
        }
        return ans1[i-1];
    }
};