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
    bool dfs(TreeNode* root, vector<int>&voyage, vector<int>&ans, int& ind){
        if (!root) return true;
        if (root->val != voyage[ind++]){
            return false;
        }
        if (root->left and root->left->val != voyage[ind]){
            ans.push_back(root->val);
            return dfs(root->right,voyage,ans,ind) and dfs(root->left,voyage,ans,ind);
        }
        else{
            return dfs(root->left, voyage,ans,ind) and dfs(root->right,voyage,ans,ind);
        }
        return true;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        int ind = 0;
        return dfs(root,voyage,ans,ind) ? ans : vector<int>{-1};
        
    }
};