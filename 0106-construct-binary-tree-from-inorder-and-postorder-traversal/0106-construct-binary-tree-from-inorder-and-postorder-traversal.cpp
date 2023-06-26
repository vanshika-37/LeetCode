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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& ind, int s, int e, unordered_map<int,int>&mp){
        if (ind < 0 || s > e) return NULL;
        int mid = mp[postorder[ind]];
        TreeNode* root = new TreeNode(postorder[ind--]);
        
        root->right = solve(inorder,postorder,ind,mid+1,e,mp);
        root->left = solve(inorder,postorder,ind,s,mid-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int ind = n-1, s = 0, e = n - 1;
        return solve(inorder, postorder,ind,s,e,mp);
        
    }
};