class Solution {
public:
    bool canPartition(vector<int>& arr) {
       long long sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }
        if (sum & 1){
           return false;
        }
        sum = sum >> 1;
        vector<vector<bool>>dp(n+1, vector<bool>(sum+1,false));
        for (int j = 0; j <= sum; j++){
            dp[0][j] = false;
        }
        for (int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= sum; j++){
                if (arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};