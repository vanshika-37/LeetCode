class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &m)
    {
        int n = m.size();
        if (n == 1)
            return m[n - 1][n - 1];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    m[i][j] += min(m[i-1][j], m[i-1][j+1]);
                else if (j == n-1)
                    m[i][j] += min(m[i-1][j], m[i-1][j-1]);
                else 
                    m[i][j] += min(m[i - 1][j - 1], min(m[i - 1][j], m[i - 1][j + 1]));
            }
        }
        return *min_element(m[n - 1].begin(), m[n - 1].end());
    }
};