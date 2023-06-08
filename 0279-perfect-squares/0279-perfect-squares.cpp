class Solution {
public:
    int numSquares(int n)
    {
        /*
        first generate a vector of all prfect squares upto that number
        then solve like minimum coin question
        */
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int sq = sqrt(i);
            if (sq * sq == i)
            {
                v.push_back(i);
            }
        }
        int sum = n;
        n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX - 1));
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= sum; j++)
        {
            if (j % v[0] == 0)
            {
                dp[1][j] = j / v[0];
            }
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (dp[n][sum] == INT_MAX - 1) ? -1 : dp[n][sum];
    }
};