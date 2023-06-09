class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long>dp(questions.size(),0);
        dp[questions.size()-1] = questions[questions.size()-1][0];
        for (int i = questions.size()-2; i>= 0; i--){
            if (i + questions[i][1] + 1 < questions.size()){
                dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i+1]);
            }
            else{
                dp[i] = max(questions[i][0] + dp[i], dp[i+1]);
            }
        }
        return dp[0];
    }
};