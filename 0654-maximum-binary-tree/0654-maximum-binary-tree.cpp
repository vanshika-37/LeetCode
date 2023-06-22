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
    TreeNode* st(vector<int>&nums, int s, int e){
        if (e < s){
            return NULL;
        }
        int ind = s;
        for (int i = s; i<= e; i++){
            ind = nums[i] > nums[ind] ? i : ind;
        }
        TreeNode* root= new TreeNode(nums[ind]);
        root->left = st(nums,s,ind-1);
        root->right = st(nums,ind+1,e); 
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int ind = 0;
        for (int i = 0; i< nums.size(); i++){
            ind = nums[i] > nums[ind] ? i : ind;
        }
        TreeNode* root = new TreeNode(nums[ind]);
        root->left = st(nums, 0, ind-1);
        root->right = st(nums, ind+1,nums.size()-1);
        return root;
    }
};