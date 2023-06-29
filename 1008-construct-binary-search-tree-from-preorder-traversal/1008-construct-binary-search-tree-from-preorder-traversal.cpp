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
      TreeNode* ok(vector<int>& pre,vector<int>& in,int &idx,int st,int ed,unordered_map<int,int> &mymap){
        if(idx>pre.size() || st>ed){
            return NULL;
        }
        
        int mid=mymap[pre[idx]];
        
        TreeNode* root = new TreeNode(pre[idx++]);
        
        root->left=ok(pre,in,idx,st,mid-1,mymap);
        
        root->right=ok(pre,in,idx,mid+1,ed,mymap);
            
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        for (int i = 0; i < preorder.size();i++){
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mp;
        for (int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return ok(preorder,inorder,idx,0,inorder.size()-1,mp);
        
    }
};