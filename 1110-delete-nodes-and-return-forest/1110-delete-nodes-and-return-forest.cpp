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
    void dfs( TreeNode* &root, vector<TreeNode*>&ans, vector<int>&to_delete){
        if (!root) return;
        dfs( root->left,ans,to_delete);
        dfs(root->right,ans, to_delete);
       if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end()){
                if (root->left ) ans.push_back(root->left);
                if (root->right) ans.push_back(root->right);
                root = NULL;
        }
    }
    

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        dfs(root,ans,to_delete);
        
        if (root and root->val != 0) ans.push_back(root);
        return ans;
    }
};