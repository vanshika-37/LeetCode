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
    void dfs(TreeNode* root, vector<int>&ans){
        if (!root) return;
       
        dfs(root->left,ans);
        dfs(root->right,ans);
         if (!root->left and !root->right){
             cout << root->val << " ";
            ans.push_back(root->val);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        dfs(root1,a);
        cout << endl;
        dfs(root2,b);
        int i = 0, j = 0;
        while(i < a.size() and j < b.size()){
            if (a[i] != b[j]) return false;
            i++;
            j++;
        }
        if (i < a.size() || j < b.size()) return false;
        return true;
    }
};