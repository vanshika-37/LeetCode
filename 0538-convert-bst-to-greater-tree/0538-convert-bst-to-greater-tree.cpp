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
    void inorder(TreeNode* root, vector<int>&ans){
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    void in(TreeNode* root, vector<int>&ans, int& i){
        if (!root) return;
        in(root->left, ans,i);
        root->val = ans[i++];
        in(root->right,ans,i);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        // inorder 0 1 2 3 4 5 6 7 8
        //sum 36 36 35 33 30 26 21 15 8
        vector<int>ans;
        inorder(root,ans);
        for (int i = ans.size() - 2; i >= 0; i--){
            ans[i] += ans[i+1];
        }
        
        for (auto &x: ans) cout << x << " ";
        cout << endl;
        int i = 0;
        in(root,ans,i);
        return root;
    }
};