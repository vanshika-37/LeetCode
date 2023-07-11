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
    void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp){
        if (!root) return;
        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
    
    void solve(TreeNode* root,  unordered_map<TreeNode*,TreeNode*>&mp, int k, vector<int>&ans, unordered_map<TreeNode*,bool>&visited, int dist){
        if (!root || visited[root]) return;
        if (dist == k){
            ans.push_back(root->val);
            return;
        }
        visited[root] = true;
        solve(root->left,mp,k,ans,visited,dist+1);
        solve(root->right,mp,k,ans,visited,dist+1);
        solve(mp[root],mp,k,ans,visited,dist+1);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        mp[root] = NULL;
        dfs(root,mp);
        int dist = 0;
        vector<int>ans;
        unordered_map<TreeNode*,bool>visited;
        solve(target,mp,k,ans,visited,dist);
        return ans;
    }
};