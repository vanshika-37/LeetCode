class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        for (int i = 0; i < m; i++){
            dp[n-1][i] = int(matrix[n-1][i]) - 48;
        }
        for(int i = 0; i < n; i++){
            dp[i][m-1] = int(matrix[i][m-1]) -48;
        }
        int mx = 0;
        for (int i = n - 2; i >= 0; i--){
            for (int j = m - 2; j >= 0; j--){
                if (matrix[i][j] == '1'){
                        if (dp[i][j+1] > 0 && dp[i+1][j+1] >0  && dp[i+1][j] > 0){
                            dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                        }
                        else{
                            dp[i][j] = 1;
                        }
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            mx = *max_element(dp[i].begin(), dp[i].end());
            maxi = max(maxi,mx);
        }
        return maxi*maxi;
    }
};