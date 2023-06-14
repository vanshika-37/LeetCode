class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>after(2, vector<int>(k+1,0));
         vector<vector<int>>curr(2, vector<int>(k+1,0));
        for (int ind = n - 1; ind >= 0; ind--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = k; cap >= 1; cap--){
                    int p = 0;
                    if (buy){
                        p = max(-prices[ind] + after[0][cap], after[1][cap]);
                    }
                    else{
                        p = max(prices[ind] + after[1][cap-1], after[0][cap]);
                    }
                    curr[buy][cap] = p;
                }
                after = curr;
            }
        }
        return curr[1][k];
    }
};