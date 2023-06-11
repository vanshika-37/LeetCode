class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int>dp(n,1);
        int mx = INT_MIN;
        for (int i = n-1; i >= 0; i--){
            for (int j = i+1; j < n; j++){
                if (pairs[i][1] < pairs[j][0]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        mx = *max_element(dp.begin(),dp.end());
        return mx;
    }
};