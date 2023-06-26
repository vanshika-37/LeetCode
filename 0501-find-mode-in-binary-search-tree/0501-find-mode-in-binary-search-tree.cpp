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
    unordered_map<int,int> cnt;
    void fill(TreeNode* root){
        if(!root) return;
        else cnt[root->val]++;
        fill(root->left);
        fill(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        fill(root);
        int max_=INT_MIN;
        vector<int> res;
        for(auto a:cnt){
            max_ = max(max_,a.second);
        }
        for(auto a:cnt){
            if(a.second==max_) res.push_back(a.first);
        }
        return res;
    }
};