class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            dp[arr[i]] = dp[arr[i] - d] + 1;
            mx = max(mx, dp[arr[i]]);
        }
        return mx;
    }
};
