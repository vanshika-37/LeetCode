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
    vector<double> levelOrder(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        if (root == NULL)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            double level = 0.00000;
            double size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *v = q.front();
                q.pop();
                if (v->left)
                    q.push(v->left);
                if (v->right)
                    q.push(v->right);
                level += (v->val);
            }
            ans.push_back(level/size);
        }
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        return levelOrder(root);
    }
};