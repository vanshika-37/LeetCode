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
    vector<int>levelOrder(TreeNode* root, vector<int>&ans){
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int mx = INT_MIN;
            for (int i = 0; i < size; i++){
                TreeNode* n = q.front();
                q.pop();
                if (n->val > mx){
                    mx = n->val;
                }
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        return levelOrder(root,ans);
    }
};