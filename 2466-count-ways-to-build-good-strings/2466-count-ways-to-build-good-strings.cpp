class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1,0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++){
             if (i >= zero) {
                dp[i] += dp[i - zero];
            }
            if (i >= one) {
                dp[i] += dp[i - one];
            }
            dp[i] %= 1000000007;
        }
        long long count = 0;
        for (int i = low; i <= high; i++){
            count += dp[i] ;
                count %= 1000000007;
        }
        return count;
    }
};