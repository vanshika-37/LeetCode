class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>n = heights;
        int count = 0;
        sort(n.begin(), n.end());
        for (int i = 0; i <n.size(); i++){
            if (n[i] != heights[i]){
                count++;
            }
        }
        return count;
    }
};