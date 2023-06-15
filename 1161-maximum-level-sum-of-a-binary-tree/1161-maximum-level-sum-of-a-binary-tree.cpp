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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root == NULL)
            return 0;
        q.push(root);
        int mx = INT_MIN, lvl = 0;
        int count = 0;
        while (!q.empty())
        {
            count++;
            int size = q.size();
            int currSum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *v = q.front();
                q.pop();
                currSum += v->val;
                if (v->left)
                {
                    q.push(v->left);\
                }

                if (v->right)
                {
                    q.push(v->right);
                }
            }
            if (currSum > mx)
                {
                    mx = currSum;
                    lvl = count;
                }
        }
        return lvl;
    }
};