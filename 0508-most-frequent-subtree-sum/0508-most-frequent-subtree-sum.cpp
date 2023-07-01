class Solution {
public:
    int findTreeSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return root -> val + findTreeSum(root -> left) + findTreeSum(root -> right);
    }
    
    void preOrderTraversal(TreeNode* root, unordered_map<int, int>& sumFreq, int& maxFreq) {
        if (!root) {
            return;
        }
        int currSum = findTreeSum(root);
        sumFreq[currSum]++;
        maxFreq = max(maxFreq, sumFreq[currSum]);
        preOrderTraversal(root -> left, sumFreq, maxFreq);
        preOrderTraversal(root -> right, sumFreq, maxFreq);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        int maxFreq = 0;
        
        preOrderTraversal(root, sumFreq, maxFreq);
        
        vector<int> maxFreqSums;
        for(auto& it : sumFreq) {
            if (it.second == maxFreq) {
                maxFreqSums.push_back(it.first);
            }
        }
        
        return maxFreqSums;
    }
};