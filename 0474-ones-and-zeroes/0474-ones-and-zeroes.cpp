class Solution {
public:
    // make a vector of pairs storing # of 0 and 1 for each string
    // make a dp vector if string can be included in ans;
    /*
    1 1
    3 1
    2 4
    0 1
    1 0
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vp;
        for (int i = 0; i < strs.size(); i++){
            int p1 = 0, p2 = 0;
            for (auto &x: strs[i]){
                x == '1' ? p2+=1: p1+=1;
            }
            vp.push_back(make_pair(p1,p2));
        }
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for (auto &x : vp){
            for (int i = m; i>= x.first; i--){
                for (int j = n; j >= x.second; j--){
                    dp[i][j] = max(1+dp[i-x.first][j-x.second], dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};