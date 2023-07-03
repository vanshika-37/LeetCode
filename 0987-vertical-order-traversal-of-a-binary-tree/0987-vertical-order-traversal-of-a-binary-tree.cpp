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
      // col row val
    vector<pair<pair<int,int>,int>>v;
    
    void dfs(TreeNode* root, int r, int c){
        if (!root) return;
        v.push_back({{c,r},root->val});
        dfs(root->left,r+1,c-1);
        dfs(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      int row = 0, col = 0;
        vector<vector<int>>ans;
        dfs(root,row,col);
        sort(v.begin(), v.end());
        // for (int i = 0; i < v.size(); i++){
        //     cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << endl;
        // }
        int i = 0;
        while(i < v.size()){
            vector<int>l;
            int j = i;
            int k = v[i].first.first;
            while(j < v.size() and i < v.size()){
                if (v[j].first.first ==k){
                    l.push_back(v[j].second);
                    j++;
                }
                else break;
            }
            i = j;
            ans.push_back(l);
        }
        return ans;
    }
};