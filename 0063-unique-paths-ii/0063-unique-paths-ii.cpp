class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0 and grid[i][j] != 1) 
                    dp[i][j] = 1;
                else if (grid[i][j] == 1)
                    continue;
                else
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
            }
        }
        return dp[n - 1][m - 1];
    }
};
