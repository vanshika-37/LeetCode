class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, pair<unsigned long long, int>>> q;
        unsigned long long num = 1, prevNum = 1;
        int lvl = 0, prevLvl = 0;
        q.push({root, {num, lvl}});
        int res = 0;
        
        while (!q.empty()) {
            TreeNode* n = q.front().first;
            lvl = q.front().second.second;
            num = q.front().second.first;
            
            if (lvl > prevLvl) {
                prevLvl = lvl;
                prevNum = num;
            }
            
            res = max(res, static_cast<int>(num - prevNum + 1));
            q.pop();
            
            if (n->left) {
                q.push({n->left, {num * 2ULL, lvl + 1}});
            }
            
            if (n->right) {
                q.push({n->right, {num * 2ULL + 1, lvl + 1}});
            }
        }
        
        return res;
    }
};
